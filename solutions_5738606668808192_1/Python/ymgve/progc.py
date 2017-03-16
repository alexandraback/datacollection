import sys, random

import psyco; psyco.full()

def find_simple_divisor(n):
    if n % 2 == 0:
        return 2
        
    i = 3
    while i*i <= n and i < 100:
        if n % i == 0:
            return i
        i += 2
    return None
    

def main():
    print "Case #1:"
    seen = {}
    while True:
        bits = "1"
        for i in xrange(30):
            bits += random.choice(("0", "1"))
        bits += "1"

        divisors = []
        good = True
        for base in xrange(2, 11):
            n = int(bits, base)
            d = find_simple_divisor(n)
            if d is None:
                good = False
                break
            divisors.append(d)
                
        if good:
            print bits, " ".join(list(str(x) for x in divisors))
            seen[bits] = True
            
        if len(seen) == 500:
            break
        
        
        
main()