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
    print "Case #{:d}: {} {}".format(i+1,a,b)