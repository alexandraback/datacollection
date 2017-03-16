def add_coin(possible, c, v):
    newpossible = possible.copy()
    for p in possible:
        if p + c <= v: newpossible.add(p+c)
    return newpossible

def bf(existing, v):
    possible = set([0])
    for c in existing:
        possible = add_coin(possible, c, v)
    if len(possible) == v+1:
        return 0

    rem_coins = set(list(range(1,v+1)))
    rem_coins.difference_update(existing)
    stack = [(possible, rem_coins, 0)]
    while len(stack) > 0:
        pos_list, rem_coins, nadded = stack.pop(0)
        for c in rem_coins:
            new_rem = rem_coins.difference(set(range(1,c)))
            np = add_coin(pos_list, c, v)
            if len(np) == v+1:
                return nadded+1
            stack.append((np, new_rem, nadded+1))

import sys

T = int(sys.stdin.readline())

for icase in range(1,T+1):
    x = sys.stdin.readline()
    [c, d, v] = [int(_u) for _u in x.split()]
    existing = [int(_u) for _u in sys.stdin.readline().strip().split()]
    assert(len(existing) == d)

    nsteps2 = bf(existing, v)
    print('Case #{}: {}'.format(icase,nsteps2))
    #if nsteps != nsteps2: print('WARNING');
    #print('Case #{}: {} {}'.format(icase,nsteps,nsteps2))
