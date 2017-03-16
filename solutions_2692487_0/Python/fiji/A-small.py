import numpy
import sys
import bisect

def read(name):
    f = open(name)
    l = f.readlines()
    l.reverse()
    r = {}
    f.close()
    r['t'] = int(l.pop())
    for i in range(r['t']):
        c = {}
        c['i'] = i+1
        c['a'],c['n'] = map(int, l.pop().split())
        c['f'] = list(map(int, l.pop().split()))
        r[i] = c
    return r


def steps(y,x):
    s = 0
    while y >= x:
        x += x - 1
        s += 1

    return (s,x)

def solve(c):
    f = c['f']
    f.sort()
    a = c['a']
    n = c['n']
    add = [0 for i in range(n)]
    sadd = [0 for i in range(n)]
    srem = [0 for i in range(n+1)]
    sc = 0
    cur = a
    fr = 0
    if a == 1:
        print("Case #%d: %d" % (c['i'], n))
        return
    for i in range(n):
        if f[i] >= cur:
            add[i], cur = steps(f[i],cur)
        cur += f[i]
        sc = sc + add[i]
        sadd[i] = sc
    r = 0
    srem[0] = n
    for i in range(n):
        srem[i+1] = sadd[i] + n - i - 1


    print("Case #%d: %d" % (c['i'], min(srem)))

def main():
    c = read(sys.argv[1])
    for i in range(c['t']):
        solve(c[i])

if __name__ == "__main__":
    main()
