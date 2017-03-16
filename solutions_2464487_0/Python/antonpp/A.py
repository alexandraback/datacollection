from math import *
filein = open('input.in', 'r')
fileout = open('Aoutput.txt', 'w')


t = int(filein.readline())

def g(r, v):
    x = 1
    t = int((-2*r+1+sqrt((2*r-1)*(2*r-1)+8*v))/4)
    while 2*t*t+(2*r-1)*t > v:
        t -= 1
    return t

for i in range(1, t + 1):
    s = filein.readline().split()
    r, v = int(s[0]), int(s[1])
    x = g(r, v)
    
    fileout.write("Case #%i: %i\n" % (i, x))