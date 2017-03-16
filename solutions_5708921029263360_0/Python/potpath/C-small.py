from collections import Counter
from copy import copy
from itertools import product

T = int(input())
for t in range(1, T + 1):
    J, P, S, K = map(int, input().split())
    p = product(''.join(map(str, range(1, J+1))), ''.join(map(str, range(1, P+1))), ''.join(map(str, range(1, S+1))))
    lastans = 1
    maxans = ['1 1 1']
    x = set(p)
    x.remove(('1', '1', '1'))
    Q = [(
        ['1 1 1'], x, Counter((('1', '1'),)), Counter((('1', '1'),)), Counter((('1', '1'),))
    )]
    sans = {tuple(maxans)}
    count = 0
    while len(Q) and count < 1e5:
        if len(maxans) == lastans:
            count += 1
        else:
            lastans = len(maxans)
            count = 0
        ans, x, jp, js, ps = Q.pop()
        for j, p, s in x:
            q = (j, p)
            w = (j, s)
            e = (p, s)
            if jp[q] < K and js[w] < K and ps[e] < K:
                nans = copy(ans)
                nx = copy(x)
                njp = copy(jp)
                njs = copy(js)
                nps = copy(ps)

                z = (j, p, s)
                nans.append(' '.join(z))
                nx.remove(z)
                njp.update((q,))
                njs.update((w,))
                nps.update((e,))

                if len(nx) and len(ans) + len(x) > len(maxans):
                    ss = tuple(nans)
                    if ss not in sans:
                        sans.add(ss)
                        Q.append((nans, nx, njp, njs, nps))
                if len(maxans) < len(nans):
                    lastans = len(maxans)
                    maxans = nans
            else:
                if len(maxans) < len(ans):
                    lastans = len(maxans)
                    maxans = ans
    print('Case #%d: %d' % (t, len(maxans)))
    print('\n'.join(maxans))
