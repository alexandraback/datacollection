# Google Code Jam 2015 Qualifying B.
# Moving half of stack isn't optimal, right?
# Start: 9, make 4,5, total cost: 6
# make 3,3,3, total cost: 5
# Right, halving isn't optimal.
# Can't improve on 3.
# 1: 1
# 2: 2
# 3: 3
# 4: 3
# 5: 4
# 6: 1 + C(3) = 4
# 7?: 1 + C(4) = 4<= No, we can't split the 3 and the 4 stack simultaneously.
# 7: split*2 eat*3 = 5
# Is moving off piles of 3 optimal?  (Not for 4)
# 8: split*2 eat*3 = 5
# 9: split*2 eat*3 = 5
# 10: split*3 eat*3 = 6 (or split + eat*5)
# 11: split*3 eat*3 = 6
# 12: split*3 eat*3 = 6
# 13: split*4 eat*3 = 7
# n: ceil(n/3) - 1 + 3 = ceil(n/3) + 2 Doesn't work for 4.
# I'm thinking 1, 2, and 4 are special cases and everything else
# follows this, but I'm unsure.  There's only a 4 minute penalty for
# failed small input attempts.
# But input is multiple plates, not 1.  We can split only one at a time.
# 4 4: split*2 eat*2 = 4
# 6 6: split*2 eat*3 = 5
# sum(ceil(nsubi/3)-1) + 3
# Special case if max is 4 and no 3.
# So, break everything into stacks of 3 (or 2 when 4), then eat
# 3 (or 2 if max was 4 and no 3).  Can split one plate at a time
# ignoring all others (except if max stack is 4 or less and no 3).
# Store numToEat -- size of largest stack when done splitting.
# Increase to stacksize for stack of 1 2 or 3, increase to 3 for
# stack > 4, increase to 2 for stack of 4.  (But only if only one 4.)
# For each plate, count splits required and adjust numToEat to {0..3}.
# Return number of splits plus numToEat.
#
# No, ceil(n/3) + 2 is wrong for 16.  That comes to 8, but split*3 to
# make stacks of 4 followed by eat*4 = 7.  Because breaking 16 into
# threes is inefficient.
# what about 18?  Rule says 8.  Can do that with stacks of 3 or 4 or 6.
# Rule is correct (because multiple of 3).
# What about 20?  Rule says 9.  Stacks of 4 or 5 cost 8.
# So stacks of sqrt(n) is optimal?
# 100? split*9 eat*10 = 19, rule says 36.
# 101? I suppose split*10 eat*10 = 20.  Or split*9 eat*11.  Or split*8
# eat*12.  Or 7,13.  Or 11,9.  Or 12,8.  But not 13,7.  Because 14*7 <
# 101.  7,13 works because 8*13 >= 101.  (That's (split+1)*eat.)
# sqrt makes sense since we want to minimize split+eat for maximum
# split*eat.
# So the maximum initial stack determines the target stack size, and
# all other stacks need to be split into that size.  Does that work?
# If max is 100 so target stack is 10 but 999 other plates start
# at 11, 10 loses.  So this is impossible without something like
# dynamic programming.
# Wait, there are only 1000 plates.  I could try all stack sizes up to
# 1000 and see which wins.  Maybe calculate cost for sqrt(max()) to
# have an upper bound for pruning.  Hey, sqrt(max()) is the minimum
# target stack, we don't need to consider anything smaller.  So if a
# stack starts at 1000, we try stack sizes 33ish to 1000.  There could
# be 999 stacks of 999, so we can't stop earlier.  But if the number
# of remaining stacks larger than i is low we could quit?  Nevermind,
# this should be fast enough.
#
# So.  Start target stacksize at sqrt(max()) - 1.  (Nevermind.)
# Iterate plates counting splits needed to reach target.  Cost of
# target is splits plus target (eating).  Repeat incrementing target
# up to max.

import sys

# How many splits does it take to convert num pancakes into stacks
# not taller than target?
def countSplits(num, target):
    if num <= 1:
        return 0
    # We do (9,3) by removing 3 twice (making 3 stacks of 3).
    return (num - 1) / target

def doCase(file):
    file.readline()             # Ignore number of plates
    plates = map(int, file.readline().split())
    bestCost = 1000
    for targetStack in range(1, 1001):
        cost = targetStack      # cost of eating stack after splitting
        for plate in plates:
            cost += countSplits(plate, targetStack) # cost of splitting
        bestCost = min(bestCost, cost)
        #print "Target {0}, cost {1}".format(targetStack, cost)
    return bestCost

def run():
    file = open(sys.argv[1])
    numCases = int(file.readline())
    for case in range(1, numCases+1):
        answer = doCase(file)
        print 'Case #{0}: {1}'.format(case, answer)
run()
