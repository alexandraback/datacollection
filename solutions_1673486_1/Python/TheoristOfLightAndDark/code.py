f = open("in.txt","r")
g = open("out.txt","w")

def cost(a,b,pro):
    ci = b-a+1
    cj = b-a+1+b+1
    return ci*(pro)+cj*(1-pro)
t = int(f.readline().strip())
for id in range(1,t+1):
    a = f.readline().split()
    b = int(a[1])
    a = int(a[0])
    ps = f.readline().split()
    p = []
    for i in ps:
        p.append(float(i))
    c4 = b+2
    pro = 1.0
    for i in p:
        pro *= i
    c1 = cost(a,b,pro)
    cd = []
    pro = 1.0
    for i in range(a):
        cd.append(cost(i,b,pro)+(a-i))
        pro = pro *p[i]
    cd.append(c4)
    cd.append(c1)
    a = min(cd)
    g.write("Case #"+str(id)+": "+str('%.6f'%(a))+'\n')
f.close()
g.close()