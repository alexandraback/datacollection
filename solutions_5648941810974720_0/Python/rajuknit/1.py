t=int(raw_input())
ii=1
while t>0:
    a=raw_input()
    b=[0]*26
    for i in a:
        b[ord(i)-65]+=1
    c=["ZERO", "TWO","SIX","EIGHT","FOUR", "ONE", "THREE", "FIVE",  "SEVEN",  "NINE"]
    cc=[0,2,6,8,4,1,3,5,7,9]
    ans=""
    jj=0
    for i in c:
        #print(b)
        mn=198192371289
        r=0
        d=[0]*26
        for k in i:
            d[ord(k)-65]+=1
        while 1:    
            r=0
            for i in range(len(d)):
                if d[i]>b[i]:
                    r=1
                    break
            if r==0:
                ans+=str(cc[jj])
                for i in range(len(b)):
                    b[i]-=d[i]
            else:
                break
        jj+=1
    #print(b)
    s=[]    
    for i in range(len(ans)):
        s.append(int(ans[i]))
    s.sort()
    ans=""
    for i in range(len(s)):
        ans+=str(s[i])
    
    print("Case #"+str(ii)+": "+str(ans))
    ii+=1
    t-=1
