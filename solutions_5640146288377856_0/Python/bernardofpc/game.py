def water_filter(rem_starts, cur_shot, w):
    r = list(rem_starts)
    return set([st for st in r if (cur_shot < st or cur_shot >= st+w)])

def fire_filter(rem_starts, cur_shot, w):
    r = list(rem_starts)
    return set([st for st in r if (st <= cur_shot and cur_shot < st+w)])

def solve(r, c, w):
    assert(r == 1)
    if w == 1 or c == w or c == w + 1:
        return c

    def best_shot(nhits, rem_shoots, rem_starts):
        if nhits == w:
            return 0

        b = 10000
        for p in rem_shoots:
            r_s = rem_shoots.copy()
            r_s.remove(p)
            _b = best_brat(nhits, r_s, rem_starts, p)
            if _b < b:
                b = _b
        return 1+b
    def best_brat(nhits, rem_shoots, rem_starts, cur_shot):
        bfire = 0
        fire_starts = fire_filter(rem_starts, cur_shot, w)
        if len(fire_starts) > 0:
            #print('{} Fire on {}, remst = {}:'.format('  '*len(rem_starts), cur_shot,
            #    fire_starts))
            bfire = best_shot(nhits+1, rem_shoots, fire_starts)

        bwater = 0
        water_starts = water_filter(rem_starts, cur_shot, w)
        if len(water_starts) > 0:
            #print('{} Water on {}, remst = {}:'.format('  '*len(rem_starts), cur_shot,
            #    water_starts))
            bwater = best_shot(nhits, rem_shoots, water_starts)

        return max(bfire, bwater)

    rem_starts = set(list(range(0, c-w+1)))
    rem_shoots = set(list(range(0, c)))
    return best_shot(0, rem_shoots, rem_starts)

import sys

T = int(sys.stdin.readline())

for icase in range(1,T+1):
    x = sys.stdin.readline()
    [r, c, w] = [int(_u) for _u in x.split()]
    nsteps2 = solve(r,c,w)
    print('Case #{}: {}'.format(icase,nsteps2))
    #if nsteps != nsteps2: print('WARNING');
    #print('Case #{}: {} {}'.format(icase,nsteps,nsteps2))
