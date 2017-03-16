
'''
Created on Apr 12, 2013

@author: herman
'''
import math

infile = open("input.txt","r")
outfile = open("output.txt","w")

trials = int(infile.readline())

for i in xrange(trials):
    r,t = [float(x) for x in infile.readline().split()]
    
    a = float(2)
    b = float(2*r-1)
    c = -t
    
    result = (-b + math.sqrt(math.pow(b,2) - 4*a*c))/(2*a)
    # print result
    result = int(math.floor(result))
    # print result
    s = "Case #%d: %d\n" % (i+1,result)
    outfile.write(s)
    print s
    
infile.close()
outfile.close()