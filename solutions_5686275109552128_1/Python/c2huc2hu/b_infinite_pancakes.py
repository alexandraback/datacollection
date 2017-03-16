# Google Code jam 2015 question B
# 

# ANALYSIS
# First observe that we do all of the splitting into the pancake piles first, and then let everyone eat. 
# Then the problem becomes "how do we make a configuration into piles that are < i pancakes high?"
# If p is the number of pancakes in a pile, then it requires ceil(p / i) - 1 moves. 
#
# Note that it will never take more than m moves, where m is the size of the largest pile, because otherwise the 
# people could just eat their pancakes without any of the splitting nonsense. 
#
# Therefore our algorithm is:
#  1. Find largest pile (size m)
#  2. Iterate through the configurations that convert pancakes to stacks < i pancakes high, where 1 <= i <= m
#  3. Find the minimum of i (to reduce the pancake pile) + sum(ceil(p/i)-1 over all piles) (to shrink the problem)

import math 

filename = 'B-large.in'

def get_min_minutes(configuration):
    """ Return the minimum time required to eat the pancakes in configuration. 
    Configuration is a list representing the number of pancakes on each plate. 
    """
    
    m = max(configuration)
    result = m
    for i in range(1, m + 1):
        t = i + sum(math.ceil(p / i) - 1 for p in configuration)
        result = min(result, t)
    
    return result 
    
if __name__ == '__main__':
    filein = open(filename)
    fileout = open(filename.split('.')[0] + '.out', 'w')
    
    t = int(filein.readline()) # num test cases
    for i in range(t):
        d = int(filein.readline()) # num non-empty plates. I can ignore this because python
        configuration = [int(j) for j in filein.readline().split()] # number of pancakes on each file
    
        fileout.write("Case #{}: {}\n".format(i + 1, get_min_minutes(configuration)))
    
    fileout.close()
    print("done")
