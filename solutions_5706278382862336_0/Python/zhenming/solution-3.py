from fractions import gcd
import math

def result(aN, aL):
            
    ancestors = 1099511627776
    x = gcd(aN, aL)
    aN /= x
    aL /= x
    
    if ancestors % aL == 0:
        
        y = ancestors / aL
        aN *= y
        z = math.log(aN,2)
        return repr(int(math.ceil(40-z)))
        
    else:
        return "impossible"      
               


f = 'A-small-attempt2'
infile = open(f+'.in', 'r')
outfile = open(f+'.out', 'w')

state = 0
caseNo = 0

for line in infile:
    
    if state == 0:
        
        t = int(line)
        state += 1
    
    elif state == 1:
        
        (n,l) = map(int, line.split('/'))
        caseNo += 1
        outfile.write('Case #'+repr(caseNo)+': '+result(n,l)+'\n')        
        