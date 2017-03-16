for cas in xrange(1,1+input()):
    print "Case #%s:" % cas,
    k,c,s = map(int, raw_input().strip().split())
    if k <= c*s:
        ans = []
        for i in xrange(0,k,c):
            index = 0
            for j in xrange(c):
                index = index*k + (i+j)%k
            ans.append(index+1)
        assert len(ans) <= s
        print ' '.join(map(str, ans))
    else:
        print 'IMPOSSIBLE'
