def read_case():
    N = int(raw_input())
    BFF = map(int, raw_input().split())
    return N, [x-1 for x in BFF]

def find_root(x, BFF):
    oldx = -1
    seen = {x}
    l = 1
    start = x
    while True:
        bff = BFF[x]
#        print oldx, x, bff
        if bff == oldx:
            # x, oldx is the root
            return l, (oldx, x), True
        elif bff == start:
            return l, (start, start), False
        elif bff in seen:
            return 0, (0, 0), False
        else:
            seen.add(bff)
            oldx = x
            x = bff
            l += 1

def solve(case):
    N, BFF = case
    roots = {}
    result = 0
    for x in range(N):
        l, pair, expandable = find_root(x, BFF)
#        print l, pair, expandable
        result = max(result, l)
        if expandable:
            oldl = roots.get(pair, 0)
            roots[pair] = max(l, oldl)
    chained = set()
    chainedl = 0
    # combine expandable circles
    for k, v in roots.items():
        if k in chained:
            continue
        k1, k2 = k
        chainedl += v + roots.get((k2, k1), 0) - 2
        chained.add(k)
        chained.add((k2, k1))
    return max(result, chainedl)


T = input()

for t in range(T):
    case = read_case()
    result = solve(case)
    print "Case #%d: %d" % (t+1, result)
