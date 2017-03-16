import math

def cost(c,f,x,i):
    res = x/(2+i*f)
    #print res
    for j in xrange(i):
        #print c/(2+j*f)
        res+= c/(2+j*f)
    return res 

cases = int(raw_input())
for count in xrange(cases):
    c,f,x = map(float,raw_input().split())
    i = math.ceil(x/c - 2/f - 1)
    if i<0:
        i=0
    #print i
    print "Case #%d: %f" % (count+1,cost(c,f,x,int(i)))

