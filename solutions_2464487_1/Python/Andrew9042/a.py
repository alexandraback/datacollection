'''
Created on Apr 26, 2013

@author: Andrew
'''
import sys
import math
sample = '''5
1 9
1 10
3 40
1 1000000000000000000
10000000000000000 1000000000000000000
'''.splitlines()

def raw_input_test():
    global sample
    if len(sample) == 0:
        return ''
    ret = sample[0]
    sample = sample[1:]
    return ret

def _print(x):
    print x
    
# == FUNCTIONS == #





# == MAIN == #
if len(sys.argv) > 1:
    fn = sys.argv[1]
    f = open(fn, 'r')
    gn = fn.rsplit('.',1)
    gn = gn[0] + '.out'
    g = open(gn, 'w')
    getline = lambda: f.readline().strip('\n')
    printline = lambda x: g.write(str(x) + '\n')
else:
    getline = raw_input_test
    printline = _print


#####################
num_cases = int(getline())
import decimal
for case_num in xrange(1,num_cases + 1):
    
    r,A = map(int, getline().split())
    #N = int((math.sqrt(8*A + 4*r**2 - 4*r + 1) - 2*r -3)/4.0 + 1)
    B = 8*A + 4*r**2 - 4*r + 1
    decimal.getcontext().prec = 300
    B = decimal.Decimal(B).sqrt()
    B = B + decimal.Decimal(-2*r -3)
    B = B / decimal.Decimal(4.0) + decimal.Decimal(1)
    C = int(B)
    
    msg = C
    printline("Case #{0}: {1}".format(case_num, msg))


#####################
if len(sys.argv) > 1:
    f.close()
    g.close()