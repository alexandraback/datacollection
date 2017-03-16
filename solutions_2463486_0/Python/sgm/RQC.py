# coding: utf-8

def pal(n):
    s = str(n)
    l = len(s)
    for i in xrange(l / 2):
        if s[i] != s[l - 1 - i]:
            return False
    return True

def even():
    for i in xrange(1, 2 ** 25):
        left = bin(i)[2:]
        right = left[::-1]
        x = int(left + right)
        if pal(x) and pal(x * x):
            yield x

def odd():
    for i in xrange(1, 2 ** 24):
        for m in ['0', '1', '2']:
            left = bin(i)[2:]
            right = left[::-1]
            x = int(left + m + right)
            if pal(x) and pal(x * x):
                yield x

def two():
    for i in xrange(25):
        k = 2 * 10 ** i
        v = k * 10 ** (i + 1) + 2
        if pal(v) and pal(v * v):
            yield v
        if i < 24:
            for m in xrange(2):
                v = (k * 10 + m) * 10 ** (i + 1) + 2
                if pal(v) and pal(v * v):
                    yield v

l = [1, 2, 3] + list(even()) + list(odd()) + list(two())
l.sort()

def find(x, p, q):
    if p >= q:
        return p
    r = (p + q) / 2
    if l[r] < x:
        return find(x, r + 1, q)
    elif l[r] > x:
        return find(x, p, r)
    return r + 1

def find_index(x):
    return find(x, 0, len_l)

n = int(raw_input())
for i in xrange(1, n + 1):
    tok = raw_input().split(' ')
    a = int(tok[0])
    b = int(tok[1])
    print 'Case #%d: %d' % (i, find_index(b) - find_index(a - 1))
