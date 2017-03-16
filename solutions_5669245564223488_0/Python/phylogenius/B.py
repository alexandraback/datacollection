import sys
from itertools import permutations

T = int(sys.stdin.readline())

def valid(x):
    s = set()
    for i in xrange(1,len(x)):
        if x[i-1] != x[i]: s.add(x[i-1])
        if x[i] in s: return False
    return True

for t in xrange(1, T+1):
    sys.stdin.readline()
    i = 0
    for x in permutations(sys.stdin.readline().split()):
        if valid(''.join(x)): i += 1
    print 'Case #{}: {}'.format(t, i)
    
