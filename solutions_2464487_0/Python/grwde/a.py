import sys

def f(C,r):
    return 2*C*C+(2*r-1)*C

T=int(raw_input())
for test in range(1,T+1):
    (r,target)=map(int,(raw_input()).split())

    Cmin=1
    Cmax=1
    while f(Cmax,r)<=target:
        Cmax=2*Cmax

    pivot=(Cmin+Cmax)/2
    while not pivot==Cmin:
        if f(pivot,r)>target:
            Cmax=pivot
        else:
            Cmin=pivot
        pivot=(Cmin+Cmax)/2

    print "Case #{0}: {1}".format(test, pivot)
