from collections import Counter

def single(func):
    return func(raw_input())

def row(func):
    return map(func, raw_input().split())

def printcase(case, out, pattern='Case #%d: %s'):
    print pattern % (case, out)

def repeat(func, times):
    return [func() for _ in xrange(times)]


T = single(int)
for t in xrange(1, T + 1):
    J, P, S, K = row(int)
    jp, js, ps = Counter(), Counter(), Counter()
    outfits = []
    for j in xrange(1, J+1):
        for p in xrange(1, P+1):
            for s in xrange(1, S+1):
                if jp[(j,p)] < K and js[(j,s)] < K and ps[(p,s)] < K:
                    jp[(j,p)] += 1; js[(j,s)] += 1; ps[(p,s)] += 1
                    outfits.append((j,p,s))
    printcase(t, len(outfits))
    print '\n'.join(' '.join(map(str, o)) for o in outfits)
