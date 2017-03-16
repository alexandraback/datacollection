T = int(raw_input())

hash = {}
def brute_force(P):
    pp = tuple(sorted([v for v in P if v > 0]))
    if not pp:
        return 0
    if pp in hash:
        return hash[pp]
    best = 1 + brute_force([v-1 for v in pp])
    for diner in xrange(len(pp)):
        for mv in xrange(1, pp[diner]):
            npp = list(pp)
            npp[diner] -= mv
            npp.append(mv)
            best = min(best, 1 + brute_force(npp))
    hash[pp] = best
    return best


for case in xrange(1, T+1):
    D = int(raw_input())
    P = map(int, raw_input().split())
    minutes = brute_force(P)
    print "Case #{}: {}".format(case, minutes)
