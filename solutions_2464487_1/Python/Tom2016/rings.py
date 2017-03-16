import math
import numpy

def isqrt(n):
    x = n
    y = (x + n // x) // 2
    while y < x:
        x = y
        y = (x + n // x) // 2
    return x

def calc(radius, paint):
    a = 2
    b = 3+2*radius
    c = 1-paint+2*radius
    d = b*b-4*a*c
    #print math.sqrt(d)
    e = isqrt(d)
    f = e
    g = int( ((-1*b)+f)/(2*a) )
   # print "d", d, "e", e,"f",f,"g",g
    return g+1
##    d = int(math.floor((-1*b+math.sqrt( b*b - 4*a*c)) / (2*a)))
##    print d+1
##    return d+1

    
##    start = 1
##    numRings = 0
##    while( paint >= 0):
##        paint-=(2*radius + start)
##        start+=4
##        numRings+=1
##    return numRings - 1

data = [line.strip() for line in open("input.txt")]
output = []
for item in data[1:]:
    line = [int(token) for token in item.split()]
    output.append(calc(line[0],line[1]))

f = open("output.txt", 'w')
for i in range(len(output)):
    f.write("Case #"+str(i+1)+": "+str(output[i])+"\n")
f.close()
