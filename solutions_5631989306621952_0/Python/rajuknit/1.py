t=int(raw_input())
ii=1
while t>0:
    a=raw_input()
    if len(a)==1:
        s=a
    else:    
        s=a[0]
        if a[1]<a[0]:
            s+=a[1]
        else:
            s=a[1]+s
        l=s[0]
        r=s[1]
        for i in range(2,len(a)):
            if a[i]<l:
                s+=a[i]
            else:
                s=a[i]+s
                l=a[i]
    print("Case #"+str(ii)+": "+str(s))
    ii+=1
    t-=1
