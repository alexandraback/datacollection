
'''
Created on Apr 12, 2013

@author: herman
'''


infile = open("input.txt","r")
outfile = open("output.txt","w")

trials = int(infile.readline())

for q in xrange(trials):
    limits = [int(x) for x in infile.readline().split()]
    Em = limits[0]
    R = limits[1]
    N = limits[2]
    vals = [int(x) for x in infile.readline().split()]
    
    best_val = [[0 for y in xrange(Em)] for x in xrange(N)]
    # initialize best_vals
    for i in xrange(Em):
        E = i+1
        best_val[-1][i] = E*vals[-1]
    
    for x in xrange(2,N+1):
        j = N-x
        for i in xrange(Em):
            E = i+1
            best_val[j][i] = max([k*vals[j] + best_val[j+1][(min(E-k+R,Em))-1] for k in xrange(E+1)])
    
    result = best_val[0][-1]
    
    s = "Case #%d: %d\n" % (q+1,result)
    outfile.write(s)
    print s
    
infile.close()
outfile.close()