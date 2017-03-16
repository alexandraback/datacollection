import sys
wt=sys.stdout.write

def cal_s(v0,a,t):
    return v0*t+a*t*t/2

def cal_join_t(v1,a,t1,x1):
    return ( v1+(v1*v1-2*a*(v1*t1-x1))**0.5 )/a

def cal_t(D,a):
    return (2*D/a)**0.5

f=open('a2.in')
NUM=int(f.readline())
i=0
while i<NUM:
    i+=1
    wt('Case #%d:\n'%i)

    l=f.readline().split(' ')
    D=float(l[0])
    N=int(l[1])
    A=int(l[2])

    TX=[]
    t1=0.0
    for n in xrange(N):
        l=map(float,f.readline().split(' '))
        TX.append(l)
        if l[0]==0:
            x1=l[1]
        else:
            v1=(l[1]-x1)/l[0]

    AS=map(float,f.readline().split(' '))
    for a in AS:
        if cal_s(0,a,cal_join_t(v1,a,t1,x1))>D:
            print cal_t(D,a)
        else:
            print (D-x1)/v1+t1
