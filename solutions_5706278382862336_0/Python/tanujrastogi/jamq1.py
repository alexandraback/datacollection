import sys
fin = open("A-small-attempt0.in","r")
fout = open("out1","w")
#fout = sys.stdout
inp = fin.readline
out = fout.write
t = int(inp())

for cases in xrange(1,t+1):

    p,q = map(long,inp().split('/'))

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

    if( (flag==True) or (flag==False and ans==-1)):
        out("Case #"+str(cases)+": "+str(ans+1)+"\n")
    else:
        out("Case #"+str(cases)+": impossible\n")
fin.close()
fout.close()
