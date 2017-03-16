from common import nt, ni, nl, line
import itertools

def solve(nums):
    
    # Map sum to list of numbers resulting
    sums = {}

    # Loop through all combos
    for c in range(1, len(nums) + 1):
        for combo in itertools.combinations(nums, c):
            s = sum(combo)
            if s in sums:
                print
                print ' '.join([str(n) for n in sums[s]])
                print ' '.join([str(n) for n in combo])
                return 
            else:
                sums[s] = combo
    print "Impossible"

T = ni(); nl()
for case in xrange(T):
    print "Case #%s:" % (case+1),
    N = ni()
    nums = []
    for n in xrange(N):
        nums.append(ni())
    solve(nums)
    nl()
