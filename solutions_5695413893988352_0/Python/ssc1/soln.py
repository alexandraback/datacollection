def mn(s):
    return s.replace('?','0')
def mx(s):
    return s.replace('?','9')
def ad(a,b):
    return str(int(a)+b)
def f(a,b):
    if len(a)==0:
        return a,b
    if a[0]==b[0]=='?':
        c,d=f(a[1:],b[1:])
        l=[(abs(int('0'+c)-int('0'+d)),'0'+c,'0'+d)]
        c,d=f('0'+a[1:],'1'+b[1:])
        l.append((abs(int(c)-int(d)),c,d))
        c,d=f('1'+a[1:],'0'+b[1:])
        l.append((abs(int(c)-int(d)),c,d))
        return min(l)[1:]
    if a[0]==b[0]:
        c,d=f(a[1:],b[1:])
        return a[0]+c,b[0]+d
    if a[0]=='?':
        a1,b1=f(b[0]+a[1:],b)
        l=[(abs(int(a1)-int(b1)),a1,b1)]
        if b[0]<'9':
            a1,b1=f(ad(b[0],1)+a[1:],b)
            l.append((abs(int(a1)-int(b1)),a1,b1))
        if b[0]>'0':
            a1,b1=f(ad(b[0],-1)+a[1:],b)
            l.append((abs(int(a1)-int(b1)),a1,b1))
        return min(l)[1:]
    if b[0]=='?':
        a1,b1=f(a,a[0]+b[1:])
        l=[(abs(int(a1)-int(b1)),a1,b1)]
        if a[0]<'9':
            a1,b1=f(a,ad(a[0],1)+b[1:])
            l.append((abs(int(a1)-int(b1)),a1,b1))
        if a[0]>'0':
            a1,b1=f(a,ad(a[0],-1)+b[1:])
            l.append((abs(int(a1)-int(b1)),a1,b1))
        return min(l)[1:]
    if a[0]<b[0]:
        return mx(a),mn(b)
    return mn(a),mx(b)
for i in range(int(raw_input())):
    c,j=raw_input().split()
    l=len(c)
    a,b=f(c,j)
    bl=[]
    def g(a,b,c,d):
        if len(b)==0:
            global bl
            bl.append((abs(int(a)-int(c)),a,c))
        elif b[0]!='?' and d[0]!='?':
            g(a+b[0],b[1:],c+d[0],d[1:])
        elif b[0]=='?' and d[0]!='?':
            for j in range(10):
                g(a+str(j),b[1:],c+d[0],d[1:])
        elif b[0]!='?' and d[0]=='?':
            for j in range(10):
                g(a+b[0],b[1:],c+str(j),d[1:])
        else:
            for j in range(10):
                for k in range(10):
                    g(a+str(j),b[1:],c+str(k),d[1:])
    g("",c,"",j)
    m=min(bl)
    print "Case #{:d}: {} {}".format(i+1,a,b)
    assert(a==m[1]and b==m[2])
    assert(len(a)==len(c)==len(b))