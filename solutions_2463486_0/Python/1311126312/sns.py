def pal(n):
    return str(n)==str(n)[::-1]
    
def sp(n):
    sq=n**0.5
    return pal(n) and int(sq)**2==n and pal(int(sq))

data=open("sns.in").readlines()
out=open("sns.out","w")
t=int(data[0])
cl=1
case=1
for i in xrange(t):
    A=int(data[cl].split()[0])
    B=int(data[cl].split()[1])
    t=0
    for j in range(A, B+1):
        if sp(j): t+=1
    out.write("Case #"+str(case)+": "+str(t)+"\n")
    case+=1
    cl+=1
