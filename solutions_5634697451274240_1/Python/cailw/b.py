with open('b.txt') as f:
    fo=open('bo.txt','w')
    f.readline()
    for t,s in enumerate(f.readlines()):
        s=s.strip()
        ans=0
        for i in range(1,len(s)):
            if s[i-1]!=s[i]:
                ans+=1
        if s[-1]=='-':
            ans+=1
        print('Case #%d:'%(t+1),ans,file=fo)
fo.close()
