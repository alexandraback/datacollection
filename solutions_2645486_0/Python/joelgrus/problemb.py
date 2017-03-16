infile = "B-small-attempt0.in"
outfile = "B-small0.out"
lines = [l.strip() for l in open(infile,"r")]

outf = open(outfile,"w")

from collections import defaultdict

import math

T = int(lines[0])
lines = lines[1:]

for loop in range(T):

    E,R,N = [int(x) for x in lines[0].split()]
    values = [int(x) for x in lines[1].split()]
    lines = lines[2:]

    scores = [None] * N

    scores[-1] = [ spend * values[-1] for spend in range(E + 1)]    
    
    i = N - 2



    while i >= 0:

        scorei = [ None ] * (E + 1)
        for start_energy in range(E + 1):
            best_value = -1
            for spend in range(0,start_energy + 1):
                next_energy = min(E, start_energy - spend + R)
                this_value = values[i] * spend
                next_value = scores[i+1][next_energy]
                total_value = this_value + next_value
                if total_value > best_value:
                    best_value = total_value
            scorei[start_energy] = best_value
        scores[i] = scorei
        i = i -1

    result = max(scores[0])

    outstr = "Case #" + str(loop+1) + ": " + str(result)
    outf.write(outstr + "\n")

outf.close()
