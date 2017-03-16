def getCycles(n):
    s = str(n)
    cycles = set([(s[i:] + s[:i]) for i in range(len(s))])
    return filter(lambda x: x > n, map(int, cycles))

T = input()

for c in range(1, T+1):
    A, B = map(int, raw_input().strip().split(' '))

    q =  map(lambda cs: filter(lambda x: A<x<=B, cs),
                         map(getCycles, range(A, B+1)))
    s = sum(map(len, q))

    print 'Case #%d:' % c, s
