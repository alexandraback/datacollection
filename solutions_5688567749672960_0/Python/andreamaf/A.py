
def solve(t):
    N = int(raw_input().strip())
    M = [N+1] * (N+1)

    M[1] = 1 
    for i in xrange(2, N+1):
        M[i] = min(1 + M[i-1], M[i])

        s = str(i)
        r = s[::-1]
        z = int(r)
        if z <= N:
            M[z] = min(M[z], 1 + M[i])

    print "Case #%d: %d" % (t, M[N])


if __name__ == '__main__':
    T = int(raw_input().strip())
    for t in xrange(1, T+1):
        solve(t)
