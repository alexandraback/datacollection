import math
def isqrt(x):
    if x < 0:
        raise ValueError('square root not defined for negative numbers')
    n = int(x)
    if n == 0:
        return 0
    a, b = divmod(n.bit_length(), 2)
    x = 2**(a+b)
    while True:
        y = (x + n//x)//2
        if y >= x:
            return x
        x = y
fin=open('input.in','r')
fout=open('output.out','w')
T=0
for line in fin:
    if(T==0):
        T+=1
        continue
    a=line.split()
    r=int(a[0])
    t=int(a[1])
    mid=r*(r-1)/2
    t+=mid
    n=(isqrt(8*t+1)-1)/2
    fout.write('Case #'+str(T)+': '+str((n-r+1)/2)+'\n')
    T+=1
fout.close()
