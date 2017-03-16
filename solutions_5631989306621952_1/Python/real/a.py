import sys, itertools
from collections import defaultdict
sys.setrecursionlimit(10000)

read_ints = lambda: map(int, raw_input().split())
read_int  = input

T = read_int()
for ca in range(1, T + 1):
    s = raw_input()
    ans = ''
    for c in s:
        ans = max(c + ans, ans + c)
    print 'Case #%d: %s' % (ca, ans)
