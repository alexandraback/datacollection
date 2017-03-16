import itertools

def needed(v, coins):
    return set(range(v+1)) - possible(coins)

def possible(coins):
    poss = set()
    for i in range(len(coins)):
        for comb in itertools.combinations(coins, i):
            poss |= set([sum(comb)])
    return poss

t = int(raw_input())
for q in range(t):
    c,n,v = map(int, raw_input().split())
    d = sorted(map(int, raw_input().split()))
    sd = set(d)
    lim = v - d[-1]
    a = 1 
    ss = set(d)
    count = 0
    while (needed(v,ss)):
        if a not in sd:
            count += 1
            ss |= set([a])
        a *= 2


    print "Case #{}: {}".format(q+1, count)
