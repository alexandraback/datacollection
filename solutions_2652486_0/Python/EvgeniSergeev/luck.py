
import sys
si = sys.stdin

T = int(si.readline())
R, N, M, K = map(int, si.readline().split())


all_subsets = [(a, b, c) for a in range(2, M+1)
                         for b in range(2, M+1)
                         for c in range(2, M+1)]
allowed = []
for (a, b, c) in all_subsets:
    this_allowed = set([1,a,b,c,a*b,a*c,b*c,a*b*c])
    allowed.append(this_allowed)
    

def solve(ks):
    candidates = []
    for i in range(len(allowed)):
        this_allowed = allowed[i]
        ok = True
        for k in ks:
            if k not in this_allowed:
                ok = False
                break
        if ok:
            candidates.append(i)

    if len(candidates) == 1:
        return all_subsets[candidates[0]]

    by_score = []
    for ic in candidates:
        a, b, c = all_subsets[ic]
        score = 0
        for k in ks:
            for pr in [1,a,b,c,a*b,a*c,b*c,a*b*c]:
                if pr == k:
                    score += 1
        by_score.append((score, ic))

    by_score.sort()
    return all_subsets[by_score[-1][1]]



print "Case #1:"
for i in range(R):
    ks = map(int, si.readline().split())
    a, b, c = solve(ks)
    print '%d%d%d' % (a, b, c)
