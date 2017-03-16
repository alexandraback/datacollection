#Naomi can get a point if he has a block which mass > Ken's min mass block
#since Naomi can just claim it heavier than Ken's max mass block.

import sys
import fractions

_pow_of_2 = set()
for i in xrange(41):
    _pow_of_2.add(2L ** i)

def lowest_terms(num1, num2):
    d = fractions.gcd(num1, num2)
    return num1/d, num2/d

def power_of_2(num):
    return num in _pow_of_2

def generation(P, Q):
    P, Q = lowest_terms(P, Q)
    if not power_of_2(Q):
        return -1
    g = 1
    P *= 2       
    while P < Q:
        P *= 2L
        g += 1
    if g > 40:
        return -1
    return g
    
def main():
    case_num = int(raw_input())
    for i in xrange(case_num):   
        line = raw_input()
        P, Q = map(long, line.split('/'))
        g = generation(P, Q)
        if g < 0:
            s = "impossible"
        else:
            s = "%d" % g
        print 'Case #%d: %s' % (i+1, s)
                
main()

