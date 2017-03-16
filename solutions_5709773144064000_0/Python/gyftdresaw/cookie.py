
'''
Created on Apr 12, 2013

@author: herman
'''


infile = open("input.txt","r")
outfile = open("output.txt","w")

trials = int(infile.readline())

def fastest(C,F,X):
    rate = 2.0 # initial rate
    time = 0.0
    # updates/comparison
    to_x = X/rate
    to_c = C/rate
    next_rate = rate+F
    c_to_x = X/next_rate
    while to_x > to_c + c_to_x:
        time += to_c
        rate = next_rate
        # update/comparison
        to_x = X/rate
        to_c = C/rate
        next_rate = rate+F
        c_to_x = X/next_rate
    
    time += to_x # last contribution
    return time


for i in xrange(trials):
    C,F,X = [float(d) for d in infile.readline().split()]
    
    time = fastest(C,F,X)

    s = "Case #%d: %.7f\n" % (i+1,time)
    outfile.write(s)
    print s
    
infile.close()
outfile.close()
