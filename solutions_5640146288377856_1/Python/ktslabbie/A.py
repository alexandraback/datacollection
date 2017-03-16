'''
Created on 10 apr. 2015

Standing Ovation

@author: Kristian
'''
import itertools
import sys

sys.setrecursionlimit(2 ** 20)

lines = [line.strip() for line in open('in.txt')]
out = open('./out.txt', 'w+')

for case in range(1, len(lines)):
    R,C,W = map(int, lines[case].split())
    min_score = W
    row_rest = C-W
    if row_rest < 0:
        out.write("Case #" + str(case) + ": " + str(0) + "\n")
        continue
    
    if W == 1:
        out.write("Case #" + str(case) + ": " + str(R*C) + "\n")
        continue
    
    if W == C:
        out.write("Case #" + str(case) + ": " + str(C+(R-1)) + "\n")
        continue
    
    
    divs = C/W
    rest = C%W
    
    if rest == 0:
        min_score += (divs*R-1)
    else:
        min_score += (divs*R)
            
    out.write("Case #" + str(case) + ": " + str(min_score) + "\n")
out.close()