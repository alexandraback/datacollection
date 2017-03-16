import math

def prod(l,k):
    if len(l)==1: return l[0]
    return k**(len(l)-1)*(l[0]-1)+prod(l[1:],k)

def solve(n):
    k,c,s=map(int,n.split())
    if k>c*s: return "IMPOSSIBLE"
    a=range(1,k+1)
    pos=[]
    for j in range(k//c):
        pos.append(prod(a[j*c:(j+1)*c],k))
    if k%c!=0: pos.append(prod(a[-c:],k))
    return ' '.join(map(str,pos))

inp=open("D-small-attempt2.in")
inp.readline() #trusting all the lines in input are important
out=open("4sa3.txt","w")
case=1
for n in inp:
    out.write("Case #"+str(case)+": "+str(solve(n[:-1]))+"\n")
    case+=1
inp.close()
out.close()
    
