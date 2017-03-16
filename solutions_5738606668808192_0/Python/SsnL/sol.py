import numpy as np

def find(n):
    assert n % 2 == 0
    bases = np.arange(2, 11)
    # pows = np.arange(n)
    # transition = np.vstack((np.power(x, pows) for x in bases)).T
    divisors = bases + 1
    seen = set()
    def hash(c):
        return ''.join(map(str, c.astype(int)))
    def branch(c):
        h = hash(c)
        if h in seen:
            return
        seen.add(h)
        # breaks at n = 32
        # assert not np.count_nonzero(np.mod(c.dot(transition), divisors))
        yield h, divisors
        for i in range(1, len(c) - 2):
            if c[i] == c[i + 1] == 1:
                nc = c.copy()
                nc[[i, i + 1]] = 0
                yield from branch(nc)
        for i in range(1, len(c) - 4):
            if c[i] == c[i + 3] == 1:
                nc = c.copy()
                nc[[i, i + 3]] = 0
                yield from branch(nc)
        for i in range(1, len(c) - 3):
            if c[i] != c[i + 2]:
                nc = c.copy()
                nc[i], nc[i + 2] = nc[i + 2], nc[i]
                yield from branch(nc)
    yield from branch(np.ones(n))

f = open('C-small-attempt0.in', 'r')
o = open('C.out', 'w')

m = int(f.readline().strip())
i = 1

while i <= m:
    n, j = list(map(int, next(f).split()))
    print('Case #{0}:'.format(i), file = o)
    c = find(n)
    for _ in range(j):
        s, d = next(c)
        print(s, ' '.join(map(str, d)), file = o)
    i += 1

f.close()
o.close()
