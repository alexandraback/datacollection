#!/usr/bin/env python3

import itertools

def nt_divisor(n):
    if n % 2 == 0:
        return 2
    for d in range(3, int(n ** 0.5), 2):
        if n % d == 0:
            return d
    return None


def solve(N, J):
    res = []
    for p in itertools.product("01", repeat=N - 2):
        divs = []
        p = "1" + "".join(p) + "1"
        for base in range(2, 11):
            div = nt_divisor(int(p, base))
            if div is None:
                break
            divs.append(div)
        else:
            res.append((p, divs))
        if len(res) == J:
            break
    return res


T = int(input())
for t in range(1, T + 1):
    N, J = map(int, input().split())
    ans = solve(N, J)
    print("Case #{}:".format(t))
    for rec in ans:
        print("{} {}".format(rec[0], " ".join(str(n) for n in rec[1])))
