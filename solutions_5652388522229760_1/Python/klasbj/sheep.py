import sys
import itertools

ALL = 0b1111111111

def tonums(x):
    ans = 0
    for y in (ord(_) - ord('0') for _ in str(x)):
        ans |= 1<<y
    return ans

def solve(n):
    if n == 0:
        return 'INSOMNIA'
    N = n
    seen = tonums(n)
    while seen != ALL:
        n += N
        seen |= tonums(n)
    return n


if __name__ == '__main__':
    lines = (int(x) for x in sys.stdin.readlines()[1:])
    for t, n in enumerate(lines):
        print("Case #{}: {}".format(t+1, solve(n)))

