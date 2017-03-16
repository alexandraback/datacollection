from string import *
from math import *
def compute(r,t):
    #n = 0
    n = int((1.0-2.0*r + sqrt(4.0*r*r - 4.0*r + 1.0  + 8.0*t))/4.0)
    if t < n*(2*r+1) + 2 * n * (n - 1):
        n -= 1
    return n

fileName = raw_input("File name: ")
f = open(fileName+".in","r")
g = open(fileName+".out","w")
n = int(f.readline()[:-1])



for i in range(n):
    line = f.readline()
    line = line[:-1].split()
    r = int(line[0])
    t = int(line[1])
    #print r,t
    g.write("Case #%d: %d\n" %(i+1, compute(r,t) ))
         

g.close()
f.close()


    
    


    
