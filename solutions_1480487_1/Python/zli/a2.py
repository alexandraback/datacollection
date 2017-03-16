#float pts
def maxi(R,pts):
    r=sum(R)
    avg=(r+pts)/len(R)
    new=[score for score in R if score<=avg]
    if len(new)==len(R):
        return avg
    else:
        return maxi(new,pts)

for case in range(input()):
    print "Case #"+str(case+1)+":",
    S=map(int,raw_input().split())[1:]
    X=float(sum(S))
    for i,score in enumerate(S):
        R=S[:i]+S[i+1:]
        low,hi=0.0,1.0
        while 1:
            if hi-low<(10**(-10)):
                break
            mid=(hi+low)/2
            other=maxi(R,X*(1-mid))
            #print hi,low,mid,score+X*mid,other
            if other>score+X*mid:
                low=mid
            else:
                hi=mid
        print "%.7f" % (hi*100),
        #print maxi(R,X)
    print

#S[i]+sum(S)*y>min(S[j]+sum(S)*y[j])
