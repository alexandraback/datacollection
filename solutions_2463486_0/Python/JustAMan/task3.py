'''
Problem C. Fair and Square
Solution by vassnlit@gmail.com
'''

# let's precompute all needed "fair and square" roots
# (numbers which when squared would be between A and B)
# they should be between 1 and 10^10 (square root of 10^100 of largest set)

# construct a fair: take a digit sequence (non-zero started), join it with reversed with
# either empty or digit in between; also add all one-digit numbers


JOINERS = [''] + [str(n) for n in xrange(10)]
ALL_FAIRS = []
# first check one-digit numbers:
for n in xrange(10):
    nn = str(n ** 2)
    if nn == nn[::-1]:
        ALL_FAIRS.append(n**2)

# now check all others
n, MAX = 1, 10**4+1 # 4 is round(14/2/2)
while n < MAX:
    ns = str(n)
    nt = ns + '%s' + ns[::-1]
    for j in JOINERS:
        nv = int(nt % j)
        nn = str(nv ** 2)
        if nn == nn[::-1]:
            # this is "square and fair" root
            ALL_FAIRS.append(int(nn))
    n += 1

ALL_FAIRS = sorted(set(ALL_FAIRS))

def solve(a, b):
    for p, v in enumerate(ALL_FAIRS):
        if v >= a:
            break
    else:
        raise ValueError('no such square a')

    for q, v in enumerate(reversed(ALL_FAIRS)):
        if v <= b:
            break
    else:
        raise ValueError('no such square b')

    return len(ALL_FAIRS) - q - p

#print solve(10, 120)
import sys
with open(sys.argv[1], 'r') as inp:
    T = int(inp.readline().strip())
    for t in xrange(T):
        A, B = [int(x) for x in inp.readline().strip().split()]
        print 'Case #%d: %d' % (t+1, solve(A, B))