T = int(raw_input())

for t in xrange(T):
    N = int(raw_input())
    i = 1
    a = range(N + 1)
    for n in xrange(N):
        rev = int(str(n)[::-1])
        if rev <= N:
            a[rev] = min(a[rev], a[n] + 1)
        a[n + 1] = min(a[n + 1], a[n] + 1)
    
    print 'Case #' + str(t + 1) + ': ' + str(a[N])
