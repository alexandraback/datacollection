def solve():
    N = int(raw_input())
    if N == 0:
        return 'INSOMNIA'
    done = [False] * 10
    m = 0
    while not all(done):
        m += N
        s = str(m)
        for ch in s:
            done[int(ch)] = True
    return m

T = int(raw_input())
for i in range(T):
    print 'Case #%d:' % (i + 1), solve()
