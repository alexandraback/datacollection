def solve(N):
    if not N:
        return 'INSOMNIA'
    digits = set()
    m = 0
    while len(digits) < 10:
        m += N
        digits.update(str(m))
    return m

for x in range(1, input() + 1):
    N = input()
    print 'Case #%d:' % x, solve(N)
