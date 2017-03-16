import os, sys, itertools, operator

def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return itertools.chain.from_iterable(itertools.combinations(s, r) for r in range(1, len(s)))
    
def subset_sums(iterable):
    stuff = {}
    for subset in powerset(iterable):
        total = sum(subset)
        if stuff.has_key(total):
            stuff[total].append(subset)
            return stuff[total]
        else:
            stuff[total] = [subset]
    return stuff

infile = open(sys.argv[1], 'r')

T = int(infile.readline())
for t in xrange(1, T+1):
    splitty = map(int, infile.readline().split())
    N = splitty[0]
    integer_set = set(splitty[1:])
    value = subset_sums(integer_set)
    print "Case #%d:" % (t)
    for v in value:
        print " ".join(map(str, v))