from bisect import bisect as bs
def solve_z():
    Z = 0
    nb, kb = NB[:], KB[:]
    for n in nb[::-1]:
        i = bs(kb, n)
        if i < len(kb):
            kb.pop(i)
        else:
            kb.pop(0)
            Z += 1
    return Z

def solve_y():
    Y = 0
    nb, kb = NB[:], KB[:]
    for _ in xrange(N):
        Y = max(Y, sum(1 for n, k in zip(nb, kb) if n > k))
        kb.pop()
        nb.pop(0)
    return Y

for T in xrange(1, input() + 1):
    N = input()
    NB = sorted(map(float, raw_input().split()))
    KB = sorted(map(float, raw_input().split()))
    print "Case #{}: {} {}".format(T, solve_y(), solve_z())
        
