T = int(raw_input())
for t in range(0,T):
    S = raw_input()
    r = S[0]
    for i in range(1,len(S)):
        if S[i]>=r[0]:
            r=S[i]+r
        else:
            r=r+S[i]
    print "Case #"+str(t+1)+":",r
        
