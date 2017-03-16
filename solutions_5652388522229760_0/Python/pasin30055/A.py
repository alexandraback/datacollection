tt = int(raw_input())
for t in xrange(tt):
    n = int(raw_input())
    if n == 0:
        ans = 'INSOMNIA'
    else:
        S = set([])
        ans = 0
        while len(S) != 10:
            ans += n
            m = ans
            while m != 0:
                S.add(m % 10)
                m /= 10
    print 'Case #' + str(t + 1) + ': ' + str(ans)
