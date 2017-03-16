from fractions import gcd
from math import log

def solve(P, Q):
    gcd_pq = gcd(P, Q)
    P /= gcd_pq
    Q /= gcd_pq
    
    f = foo(Q) / float(Q)
    if int(f) != f:
        return 'impossible'
    
    P *= f
    Q *= f
    
    a = 2**int(log(P, 2))
    
    return int(log(Q / a, 2))
    
    
def foo(x):
    for i in xrange(41):
        if x < 2**i:
            return 2**i
    return 0

                
def is_power_2(x):
    while x % 2 == 0:
        if x == 0:
            return True
        x /= 2
    return False

def main():
    output = ''
    result = ''
    with open('A-small-attempt0.in') as f:
        cases = int(f.readline()[:-1])
        for case in range(cases):
            line = f.readline()[:-1]
            N = [int(c) for c in line.split('/')]
            P, Q = [int(a) for a in N]
            result = solve(P, Q)
            
            output += 'Case #%s: %s\n' % (case + 1, result)

    with open('A-small-attempt0.out', 'w') as f:
        f.write(output)

main()