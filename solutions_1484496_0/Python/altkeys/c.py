from itertools import *
from collections import *

def solve(xs):
    ss = defaultdict(list)
    for ps in product((0,1), repeat=20):
        s = sum(p*x for p,x in zip(ps, xs))
        ss[s].append(ps)
        if len(ss[s]) == 2:
            p0, p1 = ss[s]
            return (' '.join(map(str, [x for x,p,q in zip(xs,p0,p1) if (p,q) == (1,0)])) + '\n' +
                    ' '.join(map(str, [x for x,p,q in zip(xs,p0,p1) if (p,q) == (0,1)])))
    return 'Impossible'

for t in range(1, 1+int(raw_input())):
    print 'Case #%d:\n%s' % (t, solve(map(int, raw_input().split()[1:])))
