import sys

values = {}
total = 1
g = 1
n = 1
while n <= 30:
    if total >= n:
        values[n] = g
    else:
        g += 1
        total += g
        values[n] = g
    n += 1
# print values

T = int(sys.stdin.readline().strip())
for i in xrange(T):
    C, D, V = (int(x) for x in sys.stdin.readline().strip().split())
    denominations = [int(x) for x in sys.stdin.readline().strip().split()]
    # print denominations, values[V]
    print 'Case #{}: {}'.format(i+1, len(set(range(1, values[V]+1)) - set(denominations)))
