t = input()

def gcd(a, b):
    if a == 0:
        return b
    if a > b:
        return gcd(b, a)
    return gcd(b % a, a)
    
powers_2 = set(2 ** i for i in range(41))

def less_than(r1, r2):
    a,b = r1
    c,d = r2
    return a * d < b * c

for case in xrange(1, t+1):
    num, denom = map(int, raw_input().strip().split("/"))
    d = gcd(num, denom)
    num, denom = num // d, denom // d
    if denom not in powers_2:
        print "Case #%d: impossible" % case
        continue
    generations = 1
    while less_than((num, denom), (1,2)):
        generations += 1
        num *= 2
    print "Case #%d: %d" % (case, generations)