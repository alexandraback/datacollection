from sys import stdin

def each_case(A, B, K):
    return sum(1 for a in xrange(A) for b in xrange(B) if a&b < K)
    '''
    M, m = max(A,B), min(A,B)
    Kb = bin(K)[2:]
    sumK = sum(1 for b in Kb if b == '1')
    for b in bin(m)[2:]
    return 3 ** (len(Kb) - sumK)
    '''

T = int(stdin.readline())
for t in xrange(1,T+1):
    A, B, K = map(int, stdin.readline().split())
    print 'Case #{}: {}'.format(t, each_case(A, B, K))
stdin.close()
