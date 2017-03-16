def s2a(s):
    r=s.split()
    a=[]
    for i in r:
        a.append(int(i))
    return a


def mxc(g, c):
    w=len(g[0])
    h=len(g)
    m=0
    for i in range(0,h):
       m=max(m,g[i][c])
    return m 
    
def mxr(g, r):
    w=len(g[0])
    h=len(g)
    m=0
    for i in range(0,w):
       m=max(m,g[r][i])
    return m 

data=open("lawn.in").readlines()
out=open("lawn.out","w")
t=int(data[0])
cl=1
case=1
for i in xrange(t):
    N=int(data[cl].split()[0])
    M=int(data[cl].split()[1])
    cl+=1
    g=[]
    cm=[]
    rm=[]
    for j in range(cl, cl+N):
        g.append(s2a(data[j]))
    for j in range(0,N):
        rm.append(mxr(g, j))
    for j in range(0,M):
        cm.append(mxc(g, j))
    #print cm
    #print rm
    p=True
    for r in range(0,len(g)):
        for c in range(0,len(g[0])):
            if rm[r]!=g[r][c] and cm[c]!=g[r][c]:
                p=False
                break
    if p:out.write("Case #"+str(case)+": "+"YES"+"\n")
    else:out.write("Case #"+str(case)+": "+"NO"+"\n")
    case+=1
    cl+=N

