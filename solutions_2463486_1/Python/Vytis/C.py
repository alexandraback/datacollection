
from string import ascii_lowercase

code = "C-large-1"

infile = code + ".in"
outfile = code + ".out"

def perm(n, k):
    lst = [0] * (n - k) + [1] * k
    while True:
        yield ''.join(str(x) for x in lst)
        p = None
        for i in xrange(n - 1, 0, -1):
            if lst[i] > lst[i-1]:
                p = i
                break
        if p is None:
            return
        lst[i], lst[i-1] = lst[i-1], lst[i]
        lst[i+1:] = list(reversed(lst[i+1:]))

def fs(n):
    if n == 1:
        yield 1
        yield 4
        yield 9
        return
    if n % 2 == 0:
        return
    m = (n + 1) // 2 # m >= 2
    odd = m % 2 == 1
    h = m // 2 # h >= 1
    r = 0
    mid = {1: [0, 1, 2], 2: [0, 1, 2], 3: [0, 1], 4: [0, 1]}
    for x in xrange(1, min(h, 4) + 1): # all ones (except middle)
        for p in perm(h - 1, x - 1):
            if odd:
                for midd in mid[x]:
                    yield int('1' + p + str(midd) + ''.join(reversed(p)) + '1') ** 2
            else:
                yield int('1' + p + ''.join(reversed(p)) + '1') ** 2
    yield int('2' + '0' * (m - 2) + '2') ** 2
    if odd:
        yield int('2' + '0' * (h - 1) + '1' + '0' * (h - 1) + '2') ** 2

import time

start = time.clock()
fair = [x for i in xrange(1, 14 + 1) for x in fs(i)]
end = time.clock()
print end - start


def solve(line):
    a, b = map(int, line.split())
    cnt = 0
    for x in fair:
        if a <= x <= b:
            cnt += 1
    return cnt

lines = [s.strip() for s in open(infile)]
c = int(lines[0])
f = open(outfile, "w")
for i in range(1, c+1):
    r = solve(lines[i])
    print >> f, "Case #%d:" % i, r
f.close()
