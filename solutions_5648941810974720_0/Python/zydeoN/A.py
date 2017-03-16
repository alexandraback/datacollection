#!/usr/bin/env python3

from numpy import float64   # so that float64(1)/0 == inf (avoid errors)
inf = float('inf')
read_ints = lambda : list(map(int, input().split()))


def solve(S):
    cs = {}
    for s in S:
        cs[s] = cs.get(s, 0)+1

    words = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
    code = ['Z', 'O', 'W', 'H', 'U', 'V', 'X', 'S', 'G', 'N']
    rounds = [[0, 2, 4, 6, 8], [1, 3, 7], [9, 5]]

    ans = []
    for r in rounds:
        for n in r:
            while cs.get(code[n], 0) != 0:
                ans.append(n)
                for l in words[n]:
                    cs[l] -= 1
    ans.sort()
    return ans

if __name__ == '__main__':
    T = int(input())
    for tc in range(1, T+1):
        S = input()
        ans = ''.join(map(str, solve(S)))
        print("Case #%d: %s" % (tc, ans))