'''
Created on May 12, 2013

@author: nils
'''
from solve import solve


num_cases = int(input())
for casenum in range(1, num_cases+1):
    line = input().split()
    x = int(line[0])
    y = int(line[1])
    
    start = (0,0)
    positions = [(start, "")]
    visited = set(start)
    goal = (x,y)
    
    res = solve(positions, visited, goal)

    print("Case #%d: %s" % (casenum, res))