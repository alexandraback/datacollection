#run with python2 m2.py <input >output on linux
import math

def comb(a,b):
    afac = 1
    bfac = 1
    if b>a/2:
        b = a-b
    for i in range(a-b+1,a+1):
        afac *= i
    for i in range(b):
        bfac *= i+1
    return afac/bfac
    
def binom(k,n,p):
    return comb(n,k)* p**k * (1-p)**(n-k)
    
cases = input()

for case in range(cases):
    raw = raw_input().split(" ")
    diamonds = int(raw[0])
    x = int(raw[1])
    y = int(raw[2])
    tri = int(math.sqrt(diamonds))
    for i in range(tri-3,tri+3):
        if i%2==1 and (i**2+i)/2 <= diamonds:
            tri = i
    if x<0: x = -x
    if x+y<=tri:
        print "Case #%s: %s" %(case+1, 1.0)
    elif x+y>=tri+2:
        print "Case #%s: %s" %(case+1, 0.0)
    else:
        left = diamonds-(tri**2+tri)/2    
        if y+tri+2 <= left:
            print "Case #%s: %s" %(case+1, 1.0)        
        elif y==tri+1:
            print "Case #%s: %s" %(case+1, 0.0)
        else:
            s = 0
            for i in range(y, left):
                s += binom(i+1, left, 0.5)
            print "Case #%s: %s" %(case+1, s)
