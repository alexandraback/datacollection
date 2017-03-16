from itertools import imap

DIJKSTRA = {
    ('1', '1'): ('1', 1),
    ('1', 'i'): ('i', 1),
    ('1', 'j'): ('j', 1),
    ('1', 'k'): ('k', 1),
    ('i', '1'): ('i', 1),
    ('i', 'i'): ('1', -1),
    ('i', 'j'): ('k', 1),
    ('i', 'k'): ('j', -1),
    ('j', '1'): ('j', 1),
    ('j', 'i'): ('k', -1),
    ('j', 'j'): ('1', -1),
    ('j', 'k'): ('i', 1),
    ('k', '1'): ('k', 1),
    ('k', 'i'): ('j', 1),
    ('k', 'j'): ('i', -1),
    ('k', 'k'): ('1', -1),
}

def multi(a, b):
    ret = list(DIJKSTRA[(a[0], b[0])])
    ret[1] *= a[1] * b[1]
    return tuple(ret)

def signed(x):
    return x, 1


def fact(x, times):
    num, sign = x
    if times % 2 and x[1] == -1:
        sign = -1
    else:
        sign = 1

    if x[0] == '1':
        num = '1'
    else:
        if times % 2:
            if (times - 1) % 4 == 0:
                sign *= 1
            else:
                sign *= -1
        else:
            if times % 4 == 0:
                sign *= 1
            else:
                sign *= -1
            num = '1'
    return num, sign

if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(1, T + 1):
        L, X = map(int, raw_input().split())
        S = raw_input()
        if L * X < 3:
            print "Case #%d: NO" % t
            continue

        if X > 20:
            X = X % 4 + 16
        S = str(S) * X
        stack = []
        cur = signed(S[0])
        stack.append(cur)
        for s in imap(signed, S[1:]):
            cur = multi(cur, s)
            stack.append(cur)
        if stack[-1] != ('1', -1):
            print "Case #%d: NO" % t
            continue
        f = False
        ret = False
        for s in stack:
            if s == ('i', 1):
                f = True
            if f and s == ('k', 1):
                ret = True
        if ret:
            print "Case #%d: YES" % t
        else:
            print "Case #%d: NO" % t
