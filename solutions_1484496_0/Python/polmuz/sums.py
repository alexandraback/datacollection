import sys
from collections import defaultdict
from itertools import combinations

def sums(nset):
    mysums = defaultdict(set)
    for i in range(1, len(nset)):
        for comb in combinations(nset, i):
            s = sum(comb)
            mysums[s].add(comb)
            if len(mysums[s]) > 1:
                return mysums[s]
    return 'Impossible'

# print sums([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20])
# print sums([120, 266, 858, 1243, 1657, 1771, 2328, 2490, 2665, 2894, 3117, 4210, 4454, 4943, 5690, 6170, 7048, 7125, 9512, 9600])

fin = open(sys.argv[1])
fout = open(sys.argv[2], 'w')

cases = int(fin.readline().strip())

for casen in range(1, cases+1):
    line = fin.readline().strip().split(' ')[1:]
    nset = [int(x) for x in line]
    r = sums(nset)
    fout.write("Case #%d:\n" % casen)
    if r == 'Impossible':
        fout.write("Impossible\n")
    else:
        for ss in r:
            fout.write("%s\n" % " ".join([str(x) for x in ss]))
