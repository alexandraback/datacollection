#!/usr/bin/python3
def add_diamond(diamonds_scen):
    diamonds, W = diamonds_scen
    if len(diamonds) == 0:
        diamond = (0, 0)
    else:
        diamond = (0, max(y for (x, y) in diamonds if x == 0) + 2)
    p_diamond = {diamond:1.0}
    s_diamond = {}
    while len(p_diamond) > 0:
        (x, y), w = p_diamond.popitem()
        if y == 0:
            s_diamond[(x, y)] = w
        elif (x-1, y-1) in diamonds:
            if (x+1, y-1) in diamonds:
                s_diamond[(x, y)] = w
            else:
                p_diamond[(x+1, y-1)] = w
        elif (x+1, y-1) in diamonds:
            p_diamond[(x-1, y-1)] = w
        else:
            p_diamond[(x-1, y-1)] = w / 2
            p_diamond[(x+1, y-1)] = w / 2
    return [(diamonds | set([d]), W * s_diamond[d]) for d in s_diamond]

def advance(all_diamonds):
    new_all_diamonds = []
    for diamonds in all_diamonds:
        new_all_diamonds.extend(add_diamond(diamonds))
    return new_all_diamonds

D = [[(set(), 1.0)]]
for n in range(20):
    D.append(advance(D[-1]))

T = int(input())
for t in range(1, T+1):
    N, X, Y = map(int, input().split())
    #len([None for d in D[N] if (X, Y) in d]) / len(D[N])
    print('Case #%d: %s' % (t, sum((w for d, w in D[N] if (X, Y) in d), 0.0)))
