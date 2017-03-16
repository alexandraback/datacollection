T = int(raw_input())
for w in xrange(1,T+1):
    S = raw_input() + "+"
    ans = sum([S[i-1] != S[i] for i in xrange(1,len(S))])
    print "Case #%d: %d"%(w,ans)
