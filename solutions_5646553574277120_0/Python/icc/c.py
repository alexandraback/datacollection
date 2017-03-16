#!/usr/bin/env python
def fillup(can, c, coins, v, dep, local):
    if dep >= len(coins):
        return
    for count in xrange(c+1):
        if local + count*coins[dep] > v:
            break
        can[local + count*coins[dep]] = True
        fillup(can, c, coins, v, dep + 1, local+count*coins[dep])
def solve():
    line = raw_input()
    c,d,v = [int(x) for x in line.split()]

    line = raw_input()
    coins = [int(x) for x in line.split()]

    can = [False] * (v+1)
    can[0] = True
    fillup(can, c, coins, v, 0, 0)
    ans = 0
    while not all(can):
        val = None
        for val in xrange(v):
            if not can[val]:
                break
        # print val
        new_vals = []
        if val is not None:
            ans+=1
            for x in xrange(v):
                if not can[x]:
                    continue
                for count in xrange(1, c+1):
                    if count * val + x <= v:
                        new_vals.append(count*val + x)
        for val in new_vals:
            can[val] = True
    return ans

case_num = input()
for case in range(1, case_num + 1):
    print("Case #%i: %i" % (case, solve()))

