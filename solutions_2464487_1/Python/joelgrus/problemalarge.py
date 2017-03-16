infile = "A-large.in"
outfile = "A-large.out"
lines = [l.strip() for l in open(infile,"r")]

outf = open(outfile,"w")

from collections import defaultdict
from decimal import *

import math

T = int(lines[0])
lines = lines[1:]

def max_rings(r,t):
    paint = t
    num_rings = 0
    radius = r
    paint_needed = (radius * 2) + 1
    print radius,paint_needed,paint
   
    while paint_needed <= paint:
        num_rings += 1
        paint -= paint_needed
        radius += 2
        paint_needed = (radius * 2) + 1
        print radius,paint_needed,paint
   
    return num_rings

getcontext().prec = 1000
def max_rings2(r,t):
    R = Decimal(r)
    T = Decimal(t)
    s = Decimal.sqrt( (2 * R - 1) ** 2 + 8 * T) 
    n = ( 1 - 2 * r + s) / Decimal(4.0)
    return int(n)

for loop in range(T):

    r,t = [int(x) for x in lines[0].split()]
    lines = lines[1:]

    result = max_rings2(r,t)
    outstr = "Case #" + str(loop+1) + ": " + str(result)
    outf.write(outstr + "\n")

outf.close()
