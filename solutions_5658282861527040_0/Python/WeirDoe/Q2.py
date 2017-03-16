import math
import pdb


def check(A,B,K):
    count = 0
    for a in range(A):
        for b in range(B):
            if a & b < K:
                count += 1
    return count
##    //C = m*(x-t_prev)+C_prev
##    x - t_prev = (C - C_prev)/m
##    x = (X - C_prev)/m+t_prev #when I will reach targ
##    x = (C - C_prev)/m+t_prev #when I will reach cost
##    x = (X - C_new_prev)/m+t_new_prev #when I will reach targ with an upgrade
    


infile = open('B-small-attempt0(1).in','r')
outfile = open('out.txt','w')
T = int(infile.readline())
for t in range(T):
    A,B,K = [int(a) for a in infile.readline().split(' ')]
    val = check(A,B,K)
    outfile.write('Case #'+str(t+1)+': {0}'.format(val)+'\n')
    print 'Case #'+str(t+1)+': {0}'.format(val)
        
infile.close()
outfile.close()
print 'Completed'
                
            
