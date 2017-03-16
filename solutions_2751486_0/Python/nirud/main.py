'''
Created on May 12, 2013

@author: nils
'''
from solve import solve


num_cases = int(input())
for casenum in range(1, num_cases+1):
    line = input().split()
    s = line[0]
    n = int(line[1])
    
    res = solve(s, n)

    print("Case #%d: %d" % (casenum, res))