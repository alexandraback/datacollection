def solve(A, n):
    if len(n) == 0:
        return 0
    tempOp = 0
    if A <= n[0]:
        while A <= n[0]:
            A += A - 1
            tempOp += 1
    else:
        A += n.pop(0)
    tempOp += solve(A, n[:])
    return min(tempOp, len(n))

with open('A-large.in') as infile:
    input = [l.strip() for l in infile.readlines()]

T = int(input.pop(0))

with open('output.txt', 'w') as f:
    for i in xrange(T):
        A, N = map(long, input.pop(0).split(' ', 2))
        n = map(long, input.pop(0).split(' '))
        assert len(n) == N

        n.sort()
        operations = 0
        if A == 1:
            operations += len(n)
        else:
            operations = solve(A, n)

        print 'Case #%d: %d\n' % (i + 1, operations)
        f.write('Case #%d: %d\n' % (i + 1, operations))
