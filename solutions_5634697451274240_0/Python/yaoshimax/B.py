N=int(raw_input())
for n in range(N):
    S=raw_input()
    S=S[::-1]
    p="+"
    ans=0
    for c in S:
        if c!=p:
            ans+=1
            p=c
    print "Case #%d: %d" % (n+1,ans)
