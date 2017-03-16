import sys
import itertools

def case(idx, nums):
    n = len(nums)
    for x in xrange(1, n):
        for subs in itertools.combinations(nums, x):
            s1 = set(nums)
            s2 = set(subs)
            sd = s1 - s2
            for j in xrange(1, n - x):
                for subs2 in itertools.combinations(sd, j):
                    if sum(subs) == sum(subs2):
                        print "Case #%s:\n%s\n%s" % (idx, ' '.join(str (x)  for x in subs), ' '.join(str (x)  for x in subs2))
                        return
    print "Case #%s: Impossible" % idx


lines = open('task3.in').readlines()[1:]
for i,line in enumerate(lines):
    nums = map(int, line.split()[1:])
    case(i + 1, nums)
