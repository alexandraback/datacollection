# Python 3
from collections import defaultdict


def solve(n, cache):
    if n == 1:
        return 1
    if n in cache:
        return cache[n]
    else:
        r = rev(n)
        if r < n:
            s = 1 + min(solve(n-1, cache), solve(r, cache))
        else:
            s = 1 + solve(n-1, cache)
        cache[n] = s
        return s


def rev(n):
    x = str(n)[::-1].lstrip('0')
    if len(x) < len(str(n)):
        return n
    return int(x)

if __name__ == '__main__':
    T = int(input())
    cache = defaultdict(int)
    for i in range(T):
        N = int(input())
        for j in range(1, N):
            solve(j, cache)

        count = solve(N, cache)
        """
        count = 1
        while N > 1:
            N = min(rev(N), N-1)
            count += 1
        """
        print("Case #" + str(i+1) + ": " + str(count))

