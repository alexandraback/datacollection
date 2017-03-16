import sys
import string
from fractions import gcd

# Arguments: [in] [out]
# Defaults: in='input.txt', out=stdout

def readlist(f, typ):
    return map(typ, f.readline().split())

if len(sys.argv) > 1:
    input_file = len(sys.argv)>1 and sys.argv[1] or 'input.txt'
    outf = len(sys.argv)>2 and open(sys.argv[2],'w') or sys.stdout
    with open(input_file) as f:
        T = int(f.readline())
        for x in range(T):
            P,Q = map(int, f.readline().split('/'))
            
            d = gcd(P,Q)
            k = Q/d
            while gcd(k,2) == 2:
                k = k/2 
            if k!= 1: 
                res = 'impossible'
            else:
                t = P/d
                n = Q/d
                gen = 0
                while t<n:
                    gen += 1
                    n = n/2
                res = str(gen)
            outf.write('Case #{0}: {1}'.format(x+1, res))
            outf.write('\n')
