import sys
import random

n = 3
m = range(2,5+1)
products = {}
l = len(m)
for x in m:
    for y in m:
        for z in m:
            p = [1,x,y,z,x*y,x*z,y*z,x*y*z]
            for i in p:
                s = [x,y,z]
                s.sort()
                try:
                    products[i].append( tuple(s) )
                except KeyError:
                    products[i] = []
                    products[i].append( tuple(s) )
#print len(products)
#for p in products:
#    print p, products[p]
for p in products:
    products[p] = set(products[p])

f = open( sys.argv[1] )
t = f.readline()

t = 1
output = ""
print "Case #%s: %s"%(t,output)
f.readline()

line = f.readline()
while line != "":
    k = [int(x) for x in line.split()]
    possibilities = set(products[1])
    for x in k:
        possibilities = possibilities & products[x]
    print "%s%s%s"%possibilities.pop()
    

    t += 1
    line = f.readline()
f.close()
