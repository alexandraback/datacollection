import sys

def min_count(N):
    if N <= 20:
        return N
    k = len(str(N)) - 1
    a = int(str(N)[0])
    t = 10 ** k + a
    if N % 10 == 0:
        return min_count(N - 1) + 1
    if N <= (2 * (10 ** k)):
        s = 10 ** k - 1
        z = min_count(s)
        return z + N - s
    return t + N - int(str(t)[::-1]) + 1

lines = sys.stdin.readlines()
T = int(lines[0].strip())
for i, line in enumerate(lines[1:]):
    N = int(line.strip())
    print('Case #{}: {}'.format(i + 1, min_count(N)))
