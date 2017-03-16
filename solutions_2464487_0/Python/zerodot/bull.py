from math import sqrt,floor, ceil




def ans(r, t):
    a=2
    b=(2*r-1)
    c=-t
    tr=floor((-b+sqrt(b**2-4*a*c))/(2*a))-2
    while needed(r,tr)<=t:
        tr+=1
    return tr-1

def needed(radius, rings):
    return rings*(2*rings+2*radius-1)



if __name__=='__main__':
    T=int(input())
    for i in range(T):
        a=input().split()
        a=ans(int(a[0]),int(a[1]))
        print("Case #"+str(i+1)+": "+str(a))
