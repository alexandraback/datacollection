
fr=open('input.txt','r')
fw=open('output.txt','w')

def f(x,r,t):
    return 2*x*x + (2*r-1)*x -t

T=int(fr.readline())
print T
cas = 1
while T>=0:
    [R,t]=(fr.readline().split())
    R,t=int(R),int(t)
   # print R,t
    l=0
    r=2**62
    ans  =0
    while l<=r:
        mid = (l+r)/2;
        sum = f(mid,R,t)
        if sum <= 0:
            ans = max(ans,mid)
            l=mid+1
        else :
            r=mid-1
    fw.write("Case #"+str(cas)+': '+str(ans)+'\n')
    cas += 1
  #  print ans
    T-=1
