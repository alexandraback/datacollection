from sys import stdin

def inc(a, i):
    assert i > 0
    if a[i] == 0:
        a[i] = 1
    else:
        a[i] = 0
        inc(a, i-1)

def base(a, b):
    x = 1
    r = 0
    for k in reversed(a):
        if k != 0:
            r += x
        x *= b
    return r

t = int(stdin.readline())
n, j = map(int, stdin.readline().split())

a = n * [0]
a[0] = a[n-1] = 1
d = 11 * [0]
c = 0

print 'Case #1:'
while c < j:
    ok = True
    for b in xrange(2, 11):
        num = base(a, b)
        for x in xrange(2, min(num, 100)):
            if num % x == 0:
                d[b] = x
                break
        else:
            inc(a, n-2)
            ok = False
            break
    if ok:
        ss = ''
        for k in a:
            ss += str(k)
        print ss, d[2], d[3], d[4], d[5], d[6], d[7], d[8], d[9], d[10]
        inc(a, n-2)
        c += 1
