from math import pi
t=int(raw_input())
for i in range(1,t+1):
    r,t=map(int,raw_input().split(' '))
    a=0
    b=int(1e12)
    while a<b:
        k=(a+b)/2
        temp=k+1+2*r*(k+1)+2*(k+1)*k
        if temp<=t:
            a=k+1
        else:
            b=k
    print 'Case #%d: %d\n'%(i,a)