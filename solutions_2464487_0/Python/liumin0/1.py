import os,math,gmpy2
from gmpy2 import mpfr
inputFile = 'input.txt'
inputFile = 'A-small-attempt0.in'
outputFile = 'output.txt'
gmpy2.get_context().precision=500
gmpy2.get_context().round=3
def func(r, t):
    temp = mpfr(2*r-1)
    temp1 = gmpy2.sqrt(temp*temp+8*t)
    return ((temp1-temp)/4)
    


f=open(inputFile, 'rb')
c=f.readlines()
f.close()

count = 1
total = int(c[0])
i = 1
f = open(outputFile,'wb')
while i < len(c):
    r, t = c[i].replace('\r', '').replace('\n', '').split()
    r=int(r)
    t=int(t)
    #print 'Case #%d: %d' %(count,func(r, t))
    f.write('Case #%d: %d\r\n' %(count,func(r, t)))
    count += 1
    i += 1
f.close()
