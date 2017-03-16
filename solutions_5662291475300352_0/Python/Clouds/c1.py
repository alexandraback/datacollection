import sys

def dbgprint(func):
    def newfunc(*args, **kwds):
        ret = func(*args, **kwds)
        print(args, '->', ret, file=sys.stderr)
        return ret
    return newfunc

def ins(x,y):
    if x[0]==-1:
        if x[1]==0:#all
            return y
        return x#none
    xx=max(x[0],y[0])
    yy=min(x[1],y[1])
    if xx<yy:
        return (xx,yy)
    return (-1,-1)

#@dbgprint
def calc(h):
    h1=[((360-s)*m,(720-s)*m) for (s,m) in h]
    a=(-1,0)
    for i in range(len(h1)):
        a=ins(a,h1[i])
        #print(a)
    if a[0]==-1 and a[1]==-1:
        return 1
    return 0;

def case(i):
    ln1=sys.stdin.readline();
    a1=int(ln1)
    h=[]
    for k in range(a1):
        b=[int(x) for x in sys.stdin.readline().split(" ")]
        for j in range(b[1]):
            h.append((b[0],b[2]+j))
    print("Case #"+str(i)+": "+str(calc(h)))

if __name__ == "__main__":
    n=int(sys.stdin.readline())
    [case(i) for i in range(1,n+1)]
