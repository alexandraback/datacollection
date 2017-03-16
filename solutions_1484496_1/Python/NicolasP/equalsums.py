import sys
from itertools import combinations

def solve(S):
    #print S
    d = {}
    for i in xrange(len(S)):
        for x in combinations(range(len(S)), i):
            subset = set(S[n] for n in x )
            subsetsum = sum(subset)
            if subsetsum in d and d[subsetsum].isdisjoint(subset):
                return subset, d[subsetsum]
            d[subsetsum] = subset
    return 0

def main():
    with open(sys.argv[1]) as f:
        f.readline()
        for i, line in enumerate(f):
            l = [int(x) for x in line.split()]
            res = solve(l[1:])
            print 'Case #%d:' % (i+1)
            print ' '.join(str(x) for x in res[0])
            print ' '.join(str(x) for x in res[1])

if __name__ == "__main__":
    main()
