import sys
import math

f = open( sys.argv[1] )
t = f.readline()

t = 1
line = f.readline()
while line != "":
    r, paint = [int(x) for x in line.split()]   

    circles = (1.0-2*r + math.sqrt((2*r-1)**2 + 8*paint) ) / 4

    n = int(circles)
    if 2*n*r + (n/2)*(2+(n-1)*4) > paint:
        n = n-1
        
    output = n
    print "Case #%s: %s"%(t,output)
    t += 1
    line = f.readline()
f.close()
