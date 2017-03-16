import math
import pdb
import time

global p_vals
global fracs

def gcd(a,b):
    while a:
        a, b = b%a, a
    return b
def simplify(num,dem):
    gc = gcd(num,dem)
    return (num/gc,dem/gc)

p_vals = [2**n for n in range(1,40)]
fracs = [1.0/p for p in p_vals]
def check(P,Q):
    P,Q = simplify(P,Q)
    
    if Q not in p_vals:
        return "impossible"
    for gen_ind,p_val in enumerate(p_vals):
        if P >= Q/p_val:
            return gen_ind+1
    return "impossible"
time_start = time.time()

infile = open('A-small-attempt0(3).in','r')
outfile = open('out.txt','w')
T = int(infile.readline())
for t in range(T):
    P,Q = [int(a) for a in infile.readline().split('/')]
    val = check(P,Q)
    outfile.write('Case #'+str(t+1)+': {0}'.format(val)+'\n')
    print 'Case #'+str(t+1)+': {0}'.format(val)
        
infile.close()
outfile.close()
time_end = time.time()
print 'Completed in ', (time_end-time_start)
