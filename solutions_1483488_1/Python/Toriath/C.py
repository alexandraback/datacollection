def getCycles(n):
    s = str(n)
    cycles = set([(s[i:] + s[:i]) for i in range(len(s))])
    return filter(lambda x: x > n, map(int, cycles))

T = input()

C = [0] + map(getCycles, range(1, 2000001))

for c in range(1, T+1):
    A, B = map(int, raw_input().strip().split(' '))

    q = map(lambda y: len(filter(lambda x: A <= x <= B, C[y])),
            range(A, B+1))
    s = sum(q)

    print 'Case #%d:' % c, s
