from itertools import combinations
import sys

def com_subset_sum(seq):
    for r in range(2, len(seq)):
        for subset in combinations(seq, r):
            if subset:
                for subset2 in combinations(seq, r):
                    if not (subset == subset2):
                        if sum(subset) == sum(subset2):
                            return (subset,subset2)
    return ([],[])

w = int(sys.stdin.readline().strip())
i = 1
for line in sys.stdin:
    line = line.strip().split(' ')
    line = [int (x) for x in line]
    length = line[0]
    line = line[1:]

    (s1,s2) = com_subset_sum(line)
    s1 = map(str,s1)
    s2 = map(str,s2)
    s1 = ' '.join(s1)
    s2 = ' '.join(s2)
    print "Case #"+str(i)+":"
    print s1
    print s2
    i+=1

