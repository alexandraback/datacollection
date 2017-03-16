import sys
from collections import defaultdict
import itertools


def print_solutions(filename):
    content = open(filename).read().strip().split('\n')
    test_case_count = int(content[0])
    i = 1
    tk = 1
    while tk <= test_case_count:
        j, p, s, k = [int(v) for v in content[i].split(' ')]
        c_sets = []
        sames1 = defaultdict(int)
        sames2 = defaultdict(int)
        sames3 = defaultdict(int)
        dups = []
        for jj in xrange(1, j+1, 1):
            for pp in xrange(1, p+1, 1):
                for ss in xrange(1, s+1, 1):
                    c_set = [jj, pp, ss]
                    if jj == pp == ss:
                        dups.append(c_set)
                        continue
                    if sames1[(jj, pp)] >= k:
                        continue
                    if sames2[(jj, ss)] >= k:
                        continue
                    if sames3[(pp, ss)] >= k:
                        continue
                    sames1[(jj, pp)] += 1
                    sames2[(jj, ss)] += 1
                    sames3[(pp, ss)] += 1
                    c_sets.append(c_set)
        for jj, pp, ss in dups:
            if sames1[(jj, pp)] >= k:
                continue
            if sames2[(jj, ss)] >= k:
                continue
            if sames3[(pp, ss)] >= k:
                continue
            sames1[(jj, pp)] += 1
            sames2[(jj, ss)] += 1
            sames3[(pp, ss)] += 1
            c_sets.append([jj, pp, ss])


        print("Case #%s: %s" % (tk, len(c_sets)))
        for c_set in c_sets:
            print(" ".join([str(v) for v in c_set]))
        i += 1
        tk += 1

filename = sys.argv[1]
print_solutions(filename)
