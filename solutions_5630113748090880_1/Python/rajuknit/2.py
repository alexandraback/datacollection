from collections import defaultdict
t=int(raw_input())
ii=1
while t>0:
    n=int(raw_input())
    d=defaultdict(lambda:0)
    for i in range((2*n)-1):
        a=[int(x) for x in raw_input().split()]
        for j in a:
            d[j]+=1
    s=[]        
    for i in d:
        if d[i]%2==1:
            s.append(i)
    s.sort()
    for i in range(len(s)):
        s[i]=str(s[i])
    r=' '.join(s)
    print("Case #"+str(ii)+": "+str(r))
    ii+=1
    t-=1
