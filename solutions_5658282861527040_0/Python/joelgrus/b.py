infile = "b-small-attempt0.in"
outfile = "b-small.out"

lines = [l.strip() for l in open(infile,"r")]
from collections import defaultdict, Counter
from functools import partial

num_cases = int(lines[0])
lines = lines[1:]

cases = []

for _ in range(num_cases):
    
    case = lines[0]
    lines = lines[1:]
    cases.append(case)
    
def process_case(case):
    
    a, b, k = [int(x) for x in case.split()]
    count = 0
    for i in range(a):
        for j in range(b):
            if i & j < k:
                count += 1
    return count

with open(outfile,"w") as g:
    
    for i, case in enumerate(cases):
        g.write("Case #" + str(i + 1) + ": " + str(process_case(case)) + "\n")
    

