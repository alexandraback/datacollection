import sys
fin = open("A-large.in","r")
fout = open("out1a","w")
#fout = sys.stdout
inp = fin.readline
out = fout.write
t = int(inp())

def gcd(u, v):
    return gcd(v, u % v) if v else abs(u)

def reduce(p, q):
    save = gcd(p,q)
    while save != 1:
        p/=save
        q/=save
        save = gcd(p,q)
    return p,q

for cases in xrange(1,t+1):

    p,q = map(long,inp().split('/'))
    
    p,q = reduce(p,q)

    ans = 0
    test = q
    flag = True
    
    if(p == 1 and q == 1):
        ans = -1
        flag = False

    while(test>1):
        if (test%2!=0):
            flag = False
        test>>=1

    if(flag):
        while (q>2) and p < (q/2) :
            q>>=1;
            ans+=1;
    
    if ans > 40:
        flag = False

    if( (flag==True) or (flag==False and ans==-1)):
        out("Case #"+str(cases)+": "+str(ans+1)+"\n")
    else:
        out("Case #"+str(cases)+": impossible\n")

fin.close()
fout.close()
