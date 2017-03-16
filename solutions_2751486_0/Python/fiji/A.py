import sys
import re

rex = re.compile("[bcdfghjklmnpqrstvwxyz]+")

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
        c['s'],t = l.pop().split()
        c['n'] = int(t)
        r[i] = c
    return r

def subsolve(a, b, n, m):
    r = (a+1)*(b+(m-n + 1)) + (b+1)*((m-n)**2)
    return r

def next(s, n, o):
    g = rex.search(s)
    x = 0
    if not g:
        return (0,"",0)
    if len(g.group()) < n:
        r = 0
        x = len(g.group())
    else:
        a = g.start()
        m = g.end() - g.start()
        b = len(s) - a - m
        a += o
        r = subsolve(a,b,n,m)
        x = n - 1


    return (r, s[g.end():], x)


def solve(c):
    s = c['s']
    n = c['n']
    r = 0
    x = 0
    while s:
        t,s,x = next(s,n,x)
        r += t

    print("Case #%d: %s" % (c['i'], r))

def main():
    c = read(sys.argv[1])
    for i in range(c['t']):
        solve(c[i])

if __name__ == "__main__":
    main()
