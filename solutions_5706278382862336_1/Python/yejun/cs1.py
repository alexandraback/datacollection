import sys
import fractions
import math

sys.setrecursionlimit(1000000)

f = open(sys.argv[1]) if len(sys.argv)>1 else sys.stdin

total = int(f.readline().strip())

for i in range(total):
    sys.stdout.write("Case #%d: " % int(i+1))
    P, G = map(int, f.readline().split('/'))
    fr = fractions.Fraction(P, G)
    d = round(math.log2(fr.denominator)) 
    if 2**d == fr.denominator:
        b = math.floor(math.log2(fr.numerator))
        print(d - b)
    else:
        print('impossible')
