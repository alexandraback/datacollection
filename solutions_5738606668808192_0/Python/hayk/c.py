from sympy.ntheory import factorint # pip install sympy (opensource)
import random
import sys

n = 16
m = 50

with open(sys.argv[1], 'w') as fout:
    fout.write('Case #1:\n')

    while m > 0:
        bits = [random.randint(0, 1) for i in xrange(n)]
        bits[0] = bits[n - 1] = 1
    
        works = True
    
        factors = [ ]
        for b in xrange(2, 11):
            bp = 1
            num = 0
            for bit in bits:
                num += bit * bp
                bp *= b
    
            d = factorint(num, limit=10000)
            if len(d) == 1:
                works = False
                break
    
            factors.append(d.keys()[0])
    
        if works:
            print str(num), factors
            fout.write(str(num))
            for f in factors:
                fout.write(' ' + str(f))
            fout.write('\n')
            m -= 1
        else:
            print 'no'

