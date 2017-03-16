infile = "D-small-attempt0.in"
outfile = "D-small-attempt0.out"

lines = [l.strip() for l in open(infile,"r")]
from collections import defaultdict, Counter
from itertools import permutations

num_cases = int(lines[0])
lines = lines[1:]

cases = [None for i in range(num_cases)]

for i in range(num_cases):
    N = int(lines[0])
    naomi = [float(x) for x in lines[1].split()]
    ken = [float(x) for x in lines[2].split()]
    lines = lines[3:]
    cases[i] = (N, naomi, ken)

case = cases[-1]
_, naomi, ken = case    

def best_response(naomi_actual, ken_remaining):
    beaters = [k for k in ken_remaining if k > naomi_actual]
    if beaters:
        return min(beaters)
    else:
        return min(ken_remaining)

def naomi_score(naomi, ken):
    count = 0
    for n in naomi:
        k = best_response(n, ken)
        if n > k:
            count += 1
        ken = [k2 for k2 in ken if k != k2]
    return count

def naomi_cheat_score(naomi_ordered, ken):
    count = 0
    for n in naomi_ordered:
        max_ken = max(ken)
        min_ken = min(ken)
        #print n, max_ken, min_ken
        
        if n > min_ken:
            # play against min_ken and win
            count += 1
            ken = [k2 for k2 in ken if min_ken != k2]
        elif max_ken > n:
            # say it's n - epsilon
            ken = [k2 for k2 in ken if max_ken != k2]
        else:
            # n is bigger than max ken
            count += 1
            ken = [k2 for k2 in ken if min_ken != k2]
    return count
    
with open(outfile,"w") as g:
        
    for i, case in enumerate(cases):
        _, naomi, ken = case
        score = naomi_score(naomi,ken)
        best_cheat_score = naomi_cheat_score(sorted(naomi),ken)
        result = str(best_cheat_score) + " " + str(score)
    
        g.write("Case #" + str(i + 1) + ": ")
        #g.write(str(case) + "\n")            
        g.write(result + "\n")
        

