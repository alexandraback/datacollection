# codejam 2013 round 1c

# C - great wall

import collections

def solve(queue):
    height = collections.defaultdict(int)
    success = 0
    # brute force for small problem
    while queue:
        today = queue[0][0]
        allAttacks = set()
        bestStrength = 0
        while queue and queue[0][0]==today:
            day, nAttack, west, east, strength, deltaDay, deltaPos, deltaStrength = queue.pop(0)
            if nAttack>1:
                queue.append( (day+deltaDay, nAttack-1, west+deltaPos, east+deltaPos, strength+deltaStrength, deltaDay, deltaPos, deltaStrength))
            thisAttack = set(range(west,east+1))
            bestStrength = max(bestStrength, strength)
            allAttacks |= thisAttack
            for wallPos in thisAttack:
                if height[wallPos]<strength:
                    success +=1
                    break
        for wallPos in allAttacks:
            height[wallPos] = bestStrength
        queue.sort()        

    return success

    
# day, nAttack, west, east, strength, deltaDay, deltaPos, deltaStrength

import sys
t = int(raw_input())
for caseNum in range(1,t+1):
    sys.stderr.write(str(caseNum)+"\n")
    queue = []
    nTribe = int(raw_input())
    for nt in range(nTribe):
         queue.append([int(x) for x in raw_input().split()])
    queue.sort()
    print "Case #" + str(caseNum) + ":", solve(queue)

    
    

