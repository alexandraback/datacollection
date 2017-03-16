__author__ = 'horban'

def permut(n, cur=[]):
    if len(cur) == n:
        yield cur

    for i in range(n):
        if i not in cur:
            cur.append(i)
            for p in permut(n, cur):
                yield p
            cur.pop()

def get_zip(perm, zips):
    res = ''
    for p in perm:
        res += zips[p]
    return res

def can_do(flights, perm):
    def rec_visit(cit_to_vis):
        if len(cit_to_vis) == 1:
            return True
        elif len(cit_to_vis) == 2:
            par = (cit_to_vis[0], cit_to_vis[1])
            if par in flights:
                return True
            else:
                return False
        else:
            par = (cit_to_vis[0], cit_to_vis[1])
            if par in flights:
                can = can_do(flights, cit_to_vis[1:])
                if can:
                    return True
                else:
                    return can_do(flights, [cit_to_vis[0]] + cit_to_vis[2:0])
            else:
                return False
    return rec_visit(perm)


import sys
infname = sys.argv[1]
with open(infname) as inf:
    with open(infname.replace('.in', '.out'), 'w') as outf:
        T = int(inf.readline())
        for t in range(1, T+1):
            n, m = map(int, inf.readline().split())
            zips = [inf.readline().strip() for _ in range(n)]
            pairs = set(tuple(map(int, inf.readline().strip().split())) for _ in range(m))
            rpairs = set((b, a) for a, b in pairs)
            allp = pairs.union(rpairs)
            best = None
            for perm in permut(len(zips)):
                if can_do(allp, perm):
                    cur = get_zip(perm, zips)
                    if not best or cur < best:
                        best = cur
            outf.write('Case #{}: {}\n'.format(t, best))






