with open("1.in","r") as f:
    s = f.read().splitlines()
f = open("1.out","w")
n = int(s[0])
for i in range(1,n+1):
    R = int(s[i].split()[0])
    T = int(s[i].split()[1])
    l = 0
    r = 10**18
    while l<r:
        n = (l+r+1)/2
        
        if 2*n**2+2*n*R-n<=T:
            l = n
        else:
            r = n-1
#        print n,l,r,2*n**2+n*r-n
    f.write('Case #'+str(i)+': '+str(l)+'\n')
#    print l
f.close()
