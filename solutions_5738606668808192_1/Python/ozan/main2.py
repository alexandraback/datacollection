def comb(n, m):
    if m == 0:
        return 1
    return n * comb(n-1, m-1) / m


def get(N, k):
    def next(indices):
        for count in xrange(k-2):
            if indices[k-3-count] != N-3-count:
                break
        for i in xrange(count, -1, -1):
            indices[k-3-count+i] = indices[k-3-count] + i + 1
        return indices
    if k == 2:
        yield '1' + (N-2)*'0' + '1'
    else:
        indices = range(k-2)
        while True:
            yield '1'+''.join(['1' if i in indices else '0' for i in  xrange(N-2)])+'1'
            if indices[0] == N-k+1:
                break
            indices = next(indices)

def getPrimeDivisor(N):
    sN = 1000
    for x in xrange(3, sN, 2):
        if N % x == 0:
            return x
    return N

def solveK(N, k):
    assert(k >= 2)
    assert(k <= N)
    for seq in get(N, k):
        ds = []
        for b in xrange(2, 11):
            n = int(seq, b)
            d = getPrimeDivisor(n)
            if n == d:
                yield 0
                break
            else:
                ds.append(d)
        else:
            print seq, 
            for d in ds:
                print d,
            print ''
            yield 1


def solve(N, J):
    solvers = [solveK(N, k) for k in xrange(2, N+1)]
    count = 0
    while count < J:
        for solver in solvers:
            try:
                count += next(solver)
                if count == J:
                    break
            except:
                pass
def main():
    T = int(raw_input())
    for i in xrange(1, T+1):
        N, J = map(int, raw_input().split())
        print 'Case #%d:' % i
        solve(N, J)

main()
