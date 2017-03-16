import sys

def can_add(bffs, curr, s, is_left):
    if len(curr) < 2:
        return True

    if is_left:
        n, nn = curr[0], curr[1]
    else:
        n, nn = curr[-1], curr[-2]

    return bffs[n] in [nn, s]

def is_good(bffs, curr):
    for i, x in enumerate(curr):
        good =  bffs[x] in (curr[i - 1], curr[(i + 1) % len(curr)])
        if not good:
            # print "%d bad in %s" % (x, curr)
            return False

    return True

def get_ans(bffs, curr):
    seen = set(curr)
    best_ans = []

    if is_good(bffs, curr):
        best_ans = curr

    for x in xrange(len(bffs)):
        if x in seen:
            continue
        if can_add(bffs, curr, x, True):
            new_curr = []
            new_curr.append(x)
            new_curr.extend(curr)
            res = get_ans(bffs, new_curr)
            if len(res) > len(best_ans) and is_good(bffs, res):
                best_ans = res
        if can_add(bffs, curr, x, False):
            new_curr = []
            new_curr.extend(curr)
            new_curr.append(x)
            res = get_ans(bffs, new_curr)
            if len(res) > len(best_ans) and is_good(bffs, res):
                best_ans = res

    return best_ans



T = int(sys.stdin.readline())

for tc in xrange(1, T + 1):
    N = int(sys.stdin.readline())
    bff = [int(w) - 1 for w in sys.stdin.readline().split()]

    ans = -1

    for x in xrange(N):
        res = get_ans(bff, [x])

        if res is not None:
            ans = max(ans, len(res))

    print "Case #%d: %d" % (tc, ans)


