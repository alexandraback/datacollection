from sys import stdin

def each_case(N):
    if N:
        iN = N
        digits = set()
        while True:
            digits |= set(s for s in str(iN))
            if len(digits) >= 10:
                return iN
            iN += N
    else:
        return 'INSOMNIA'

T = int(stdin.readline())
for t in xrange(1,T+1):
    N = int(stdin.readline())
    print 'Case #{}: {}'.format(t, each_case(N))
