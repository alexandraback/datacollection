import sys
t=int(raw_input())
for cs in range(1,t+1):
    A,B=map(int,raw_input().split(' '))
    res=0
    for n in range(A,B+1):
        s = str(n)
        m = {}
        for i in range(1,len(s)):
            s2 = s[(len(s)-i):]+s[:(len(s)-i)]
            n2 = int(s2)
            if n2>n and not m.has_key(n2) and s2[0]!='0' and n2>=A and n2<=B:
                res+=1
                #print n,n2
                m[n2]=1
    print 'Case #%d: %d' % (cs,res)
