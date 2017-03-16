import sys

sys.stdin = open('in')
sys.stdout = open('out', 'w')


def make_array(initial, *dimensions):
    array = []
    last = [array]
    for i, d in enumerate(dimensions):
        if i == len(dimensions) - 1:
            for a in last:
                for _ in xrange(d):
                    a.append(initial)
        else:
            new_arrs = []
            for a in last:
                for _ in xrange(d):
                    new_arr = []
                    new_arrs.append(new_arr)
                    a.append(new_arr)
            last = new_arrs
    return array


def best_dimensions(n, w, h):
    ideal_w = (n + 1) // 2
    ideal_h = (n + 1) / ideal_w
    if ideal_w > w:
        ideal_w -= abs(ideal_w - w)
        ideal_h = (n + 1) / ideal_w
    elif ideal_h > h:
        ideal_h -= abs(ideal_h - h)
        ideal_w = (n + 1) / ideal_w
    print ideal_w, ideal_h
    return (ideal_w, ideal_h)

for case in xrange(int(raw_input())):
    n, m, k = map(int, raw_input().split())
    if k <= 3 or n <= 2 or m <= 2:
        print('Case #{}: {}'.format(case + 1, k))
        continue
    costs = make_array(0, n - 2, m - 2)
    best = 2**31
    for r in xrange(n - 2):
        for c in xrange(m - 2):
            stones = ((r + 1) + (c + 1)) * 2
            covered = stones + (r + 1) * (c + 1)
            if covered >= k and covered < best:
                best = stones
            costs[r][c] = (stones, covered)
    for row in costs:
        print row
    if best == 2**31:
        # figure out how many edges we need to cover
        stones, cover = costs[r - 1][c - 1]
        assert k > cover
        diff = abs(k - cover)
        print('Case #{}: {}'.format(case + 1, stones + diff))
    else:
        print('Case #{}: {}'.format(case + 1, best))
