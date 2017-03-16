import sys
myin=open("a.in")
sys.stdin=myin
myfile=open("newout.txt",mode='a')
sys.stdout=myfile
t=int(sys.stdin.readline())
cps=2.0
for i in range(t):
    C,F,X=map(float,sys.stdin.readline().split())
    #init=2
    ans=0
    cps=2.0
    while(True):
        ft1=X/cps
        ft2=C/cps+X/(cps+F)
        if(ft1<ft2):
            ans+=ft1
            break
        else:
            ans+=C/cps
            cps+=F
    print "Case #"+str(i+1)+": "+str((round(ans,7)))
myin.close()
myfile.close()
