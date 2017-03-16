from sys import stdin 
from bisect import bisect

def each_case(stdin):
    N = int(stdin.readline())
    Naomi = sorted(float(s) for s in stdin.readline().split())
    Ken = sorted(float(s) for s in stdin.readline().split())

    War = 0
    Ken_c = Ken[:]
    for block in Naomi:
        if Ken_c[-1] < block:
            War += 1
            del Ken_c[0]
        else:
            del Ken_c[bisect(Ken_c, block)]

    Deceitful = 0
    for block in Naomi:
        if Ken[0] < block:
            Deceitful += 1
            del Ken[0]
        else:
            Ken.pop()

    return '{} {}'.format(Deceitful, War)


T = int(stdin.readline())
for t in xrange(T):
    print 'Case #{}: {}'.format(t+1, each_case(stdin))
stdin.close()
