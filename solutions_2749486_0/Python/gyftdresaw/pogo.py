
'''
Created on Apr 12, 2013

@author: herman
'''


infile = open("input.txt","r")
outfile = open("output.txt","w")

trials = int(infile.readline())


for i in xrange(trials):
    (x,y) = [int(z) for z in infile.readline().split()]
    s = ''
    if x > 0:
        for j in xrange(abs(x)):
            s += 'WE'
    else:
        for j in xrange(abs(x)):
            s += 'EW'
    
    if y > 0:
        for j in xrange(abs(y)):
            s += 'SN'
    else:
        for j in xrange(abs(y)):
            s += 'NS'
    
    result = s
    s = "Case #%d: %s\n" % (i+1,result)
    outfile.write(s)
    print s
    
infile.close()
outfile.close()