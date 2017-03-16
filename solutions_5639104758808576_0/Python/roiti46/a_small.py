T = int(raw_input())
for loop in xrange(T):
    Sm,S = raw_input().split()
    Sm = int(Sm)

    histo = [0]*(Sm+1)
    
    for i in xrange(Sm+1):
        histo[i] = int(S[i])
    
    for i in xrange(1,Sm+1):
        histo[i] += histo[i-1]

    ans = 0
    for i in xrange(1,Sm+1):
        if histo[i-1]+ans < i:
            ans += i-(histo[i-1]+ans)
    print "Case #%d: %d"%(loop+1, ans)
