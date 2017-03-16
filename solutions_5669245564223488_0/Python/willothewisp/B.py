from collections import defaultdict
from itertools import permutations

from pprint import pprint


MOD = 10**9 + 7


def ok(c):
    s = set()
    cur = None
    for ch in c:
        if cur != None and cur != ch and ch in s:
            return False
        s.add(ch)
        cur = ch
    return True


def solve(N, cars):
    if any((not ok(c) for c in cars)):
        return 0

    num = defaultdict(int)
    for c in cars:
        for ch in set(c):
            num[ch] += 1
    for c in cars:
        for ch in set(c):
            if c[0] != ch and c[-1] != ch and num[ch] > 1:
                return 0

    succ = {}
    pred = {}
    for c in cars:
        if c[0] != c[-1]:
            if c[0] in succ or c[-1] in pred:
                return 0
            succ[c[0]] = c[-1]
            pred[c[-1]] = c[0]

    ans = 1

    n = 0
    for ch in set((c[0] for c in cars)):
        s = {ch}
        while ch in succ:
            ch = succ[ch]
            if ch in s:
                return 0
        if ch not in pred:
            n += 1
    for i in range(1, n + 1):
        ans = ans * i % MOD

    for ch in num:
        n = num[ch] - (ch in succ) - (ch in pred)
        for i in range(1, n + 1):
            ans = ans * i % MOD



    return ans


def solve_slow(N, cars):
    ans = 0
    for p in permutations(cars):
        ans += ok(''.join(p))
        ans %= MOD
    return ans


def main():
    T = int(input())
    for tc in range(T):
        N = int(input())
        cars = input().split()
        print("Case #{}: {}".format(tc + 1, solve(N, cars)))


if __name__ == "__main__":
    main()
