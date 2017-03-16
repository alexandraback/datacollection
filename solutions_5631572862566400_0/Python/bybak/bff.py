from itertools import combinations, permutations


















def ok(p, n, bffs):
    for i in range(1,n-1):
        if (p[i], p[i-1]) not in bffs and (p[i], p[i+1]) not in bffs:
            return False
    resultlast = (p[n-1],p[0]) in bffs or (p[n-1], p[n-2]) in bffs
    resultfirst = (p[0], p[n-1]) in bffs or (p[0], p[1]) in bffs
    # if resultlast and resultfirst:
    #     print [a for a in p]
    return resultlast and resultfirst

def max_circle(N, bffs):
    for i in reversed(range(N)):
        for c in combinations(range(N), i+1):
            for p in permutations(c):
                if ok(p, i+1, bffs):
                    # print "returning %d" % (i+1)
                    return i+1
    return 0


T = int(raw_input())
for i in range(T):
    N = int(raw_input())
    S = map(int, raw_input().split())
    bffs = set(zip(range(N), map(lambda x: x-1, S)))
    # print bffs
    # for j in range(N):
    #     bffs
    print "Case #%d: %s" % (i + 1, max_circle(N, bffs))