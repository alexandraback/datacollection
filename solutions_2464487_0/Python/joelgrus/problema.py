infile = "A-small-attempt0.in"
outfile = "A-small0.out"
lines = [l.strip() for l in open(infile,"r")]

outf = open(outfile,"w")

from collections import defaultdict

import math

T = int(lines[0])
lines = lines[1:]

def max_rings(r,t):
    paint = t
    num_rings = 0
    radius = r
    paint_needed = (radius * 2) + 1
    #print radius,paint_needed,paint
   
    while paint_needed <= paint:
        num_rings += 1
        paint -= paint_needed
        radius += 2
        paint_needed = (radius * 2) + 1
        #print radius,paint_needed,paint
   
    return num_rings

for loop in range(T):

    r,t = [int(x) for x in lines[0].split()]
    lines = lines[1:]

    result = max_rings(r,t)
    outstr = "Case #" + str(loop+1) + ": " + result
    outf.write(outstr + "\n")

outf.close()
