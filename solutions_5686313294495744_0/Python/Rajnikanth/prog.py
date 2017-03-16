t= input()
for T in xrange(1,t+1):
    print "Case #"+str(T)+":",
    ans = 0
    n = input()
    a = {}
    b = {}
    pa = []
    for i in xrange(n):
        x,y = raw_input().split()
        pa += [(x,y)]
        a[x]=0
        b[y]=0
    for i in pa:
        a[i[0]]+=1
        b[i[1]]+=1
    for i in xrange(1<<n):
        tpa = []
        cn = bin(i).count('1')
        ncn = n-cn
        for j in xrange(n):
            if(((1<<j)&i)!=0):
                tpa+=[pa[j]]
                a[pa[j][0]]-=1
                b[pa[j][1]]-=1
        ch = 0
        for j in tpa:
            if(a[j[0]]>0 and b[j[1]]>0):
                ch+=1
        if(ch==cn):
            ans = max(ans,cn)
        for j in xrange(n):
            if(((1<<j)&i)!=0):
                a[pa[j][0]]+=1
                b[pa[j][1]]+=1
    print ans
        

