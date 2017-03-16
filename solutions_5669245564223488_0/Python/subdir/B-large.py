#!/usr/bin/python3

import sys
from collections import Counter, defaultdict
from itertools import groupby, chain

def F(n):
    x = 1
    for i in range(2, n+1):
        x *= i
    return x

def solve(trains):
#    print(trains)
    trains = ["".join(l for l, grp in groupby(t)) for t in trains]
    for t in trains:
        if any(cnt != 1 for cnt in Counter(t).values()):
            return 0

    dups = defaultdict(list)
    dups_cnt = defaultdict(int)
    i = 0
    while i < len(trains):
#        print(i, trains, dups)
        t = trains[i]
        if t[0] == t[-1]:
            dups[t[0]].append(t)
            dups_cnt[t[0]] += 1
            del trains[i]
        else:
            i += 1
#    print(dups)

#    print(trains)
    new_trains = []
    while trains:
        t = trains.pop()
        for i, t2 in enumerate(trains):
            if t[-1] == t2[0]:
                trains[i] = t + ("".join(dups.pop(t[-1], []))) +  t2
                break
            elif t2[-1] == t[0]:
                trains[i] = t2 + ("".join(dups.pop(t2[-1], []))) + t
                break
        else:
            new_trains.append(t)

    for d, dd in dups.items():
        new_trains.extend(dd)
    trains = new_trains
    new_trains = []
    while trains:
        t = trains.pop()
        for i, t2 in enumerate(trains):
            if t[-1] == t2[0]:
                trains[i] = t + ("".join(dups.pop(t[-1], []))) +  t2
                break
            elif t2[-1] == t[0]:
                trains[i] = t2 + ("".join(dups.pop(t2[-1], []))) + t
                break
        else:
            new_trains.append(t)

#    print(new_trains)

    if any(cnt!=1 for cnt in Counter(l for l, grp in groupby("".join(new_trains))).values()):
        return 0

    res = F(len(new_trains))
#    print(res, dict(dups))
    for d, c in dups_cnt.items():
        res *= F(c)

    return res

def main():
    T = int(next(sys.stdin))
    for i in range(1, T+1):
        N = int(next(sys.stdin))
        trains = next(sys.stdin).split()
        print("Case #{}: {}".format(i, solve(trains) % 1000000007))

if __name__ == '__main__':
    main()

