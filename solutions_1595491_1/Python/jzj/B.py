def f1(a):
    res=a/3
    if a%3>0: res+=1
    return res

def f2(a):
    if a==0: return 0
    res=(a/6)*2
    if a%6>=5: res+=3
    elif a%6>=2: res+=2
    elif a%6>=0: res+=1
    return res

T = input()
for Case in xrange(1,T+1):
    t=map(int,raw_input().split())
    n,s,p = t[:3]
    t = t[3:]
    ans = 0
    for item in t:
        if f1(item)>=p: ans+=1
        elif s and f2(item)>=p:
            s-=1
            ans+=1
        #print s,ans
    print "Case #"+str(Case)+":", ans