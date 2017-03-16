#infile = "A-large.in"
infile = "b-test.in"
outfile = "B-test.out"


lines = [l.strip() for l in open(infile,"r")]
from collections import defaultdict, Counter
from functools import partial

num_cases = int(lines[0])
lines = lines[1:]

cases = [None for i in range(num_cases)]


for i in range(num_cases):
    cases[i] = [float(x) for x in lines[i].split()]

def time_to_win(cost, gain, goal):
    rate = 2.0
    ttime = 0.0
    cookies = 0.0
        
    num_farms = 0
    best = None
    
    while True:
        time_to_goal = ttime + goal / rate
        
        if best is None:
            best = time_to_goal
        elif time_to_goal > best:
            return best
        else:
            best = time_to_goal
        
        time_to_afford = cost / rate
        ttime += time_to_afford
        rate += gain
        num_farms += 1
           
def process_case(case):
    cost, gain, goal = case
    
    return time_to_win(cost,gain,goal)
    
with open(outfile,"w") as g:
        
    for i, case in enumerate(cases):
        g.write("Case #" + str(i + 1) + ": " + str(process_case(case)) + "\n")
    

