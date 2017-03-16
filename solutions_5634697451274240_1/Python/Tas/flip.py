import itertools
def count(s):
    d = -1 if s[-1] == '+' else 0
    return len( list( itertools.groupby(s))) + d

N = int(raw_input())
for i in xrange(N):
    w = count(raw_input().lstrip().rstrip())
    print "Case #{0}:".format(i+1),w