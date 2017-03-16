def pal(n):
    return str(n)==str(n)[::-1]
    
def sp(n):
    s=n**2
    return pal(s)

def nthpal(n, t):
    s=str(n)
    if t%2==1:
        return int(s+(s[:-1])[::-1])
    else:
        return int(s+s[::-1])
    
data=open("sns2.in").readlines()
out=open("sns2.out","w")
t=int(data[0])
cl=1
case=1
fns=[]
mn=1
mx=10**14
for j in range(1, 10**4):
    n=nthpal(j,0)
    if sp(n) and n**2<=mx and n**2>=mn:
        fns.append(n**2)
        print n**2
    n=nthpal(j,1)
    if sp(n) and n**2<=mx and n**2>=mn:
        fns.append(n**2)
        print n**2
print len(fns)
for i in xrange(t):
    A=int(int(data[cl].split()[0]))
    B=int(int(data[cl].split()[1]))
    ta=0
    for i in fns:
        if i>=A and i<=B:
            ta+=1
    out.write("Case #"+str(case)+": "+str(ta)+"\n")
    print("Case #"+str(case)+": "+str(ta))
    case+=1
    cl+=1
