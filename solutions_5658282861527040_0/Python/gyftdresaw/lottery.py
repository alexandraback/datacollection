
'''
Created on Apr 12, 2013

@author: herman
'''


infile = open("input.txt","r")
outfile = open("output.txt","w")

trials = int(infile.readline())

def dum_test(x,y,K):
    return (x & y) < K

def dum_count(A,B,K):
    count = 0
    for i in xrange(A):
        for j in xrange(B):
            if dum_test(i,j,K):
                count += 1
    return count

for i in xrange(trials):
    A,B,K = [int(s) for s in infile.readline().split()]
    print A,B,K

    c = dum_count(A,B,K)

    s = "Case #%d: %d\n" % (i+1,c)
    outfile.write(s)
    print s
    
infile.close()
outfile.close()
