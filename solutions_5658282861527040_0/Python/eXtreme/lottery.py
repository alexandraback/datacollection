__author__ = 'horban'
def how_many(a, b, k):
    cnt = 0
    for i in range(a):
        for j in range(b):
            if (i & j) < k:
                cnt += 1
    return cnt

import sys
infname = sys.argv[1]
with open(infname) as inf:
    with open(infname.replace('.in', '.out'), 'w') as outf:
        T = int(inf.readline())
        for t in range(1, T+1):
            a, b, k = map(int, inf.readline().split())
            outf.write('Case #{}: {}\n'.format(t, how_many(a, b, k)))

