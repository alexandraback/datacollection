import numpy as np
from fractions import Fraction
rfile = file('Q1small.in', 'r')
wfile = file('Q1small.out', 'w')
num_of_cases = int(rfile.readline().strip())
twoforty = 2**40
for case in range(1, num_of_cases+1):
    #write result
    P,Q = map(int, rfile.readline().strip().split('/'))
    f = Fraction(P,Q)
    P = f.numerator
    Q = f.denominator
    if twoforty%Q == 0:
        a = twoforty/Q
        b = a*P
        k = 40 - np.floor(np.log2(b))
        to_write = str(int(round(k)))
    else:
        to_write = 'impossible'
    wfile.write('Case #'+str(case)+': '+to_write+'\n')
