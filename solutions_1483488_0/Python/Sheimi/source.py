from collections import defaultdict

def shift(n, a, b, l, d):
    m = n
    t = n
    for i in range(l-1):
        first = t / d
        remain = t % d
        result = remain * 10 + first
        t = result
        if result >= a and result < m:
            m = result
    return m


def cal(i):
    i = i + 1

    raw = raw_input()
    raw = raw.split()

    a, b = int(raw[0]), int(raw[1])

    k = defaultdict(int)
    l = len(str(a))
    d = 10 ** (l-1)
    for x in range(a, b+1):
        y = shift(x, a, b, l, d) 
        k[y] += 1
    m = lambda x: x * (x-1) /2
    k = [m(x) for x in k.values()]
    s = sum(k)
    print "Case #%d: %d" % (i, s)


if __name__ == '__main__':
    i = int(raw_input())
    for x in range(i):
        cal(x)
