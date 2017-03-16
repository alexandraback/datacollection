import numpy
import sys
import math

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
        c['r'],c['t'] = map(int, l.pop().split())
        r[i] = c
    return r

def calc(t,r):
    x = 0.5 * (r - 0.5)
    n = math.sqrt((0.5*t) + (x**2)) - x
    return n

def solve(c):
    r = c['r']
    t = c['t']
    a = calc(t, r)
    print("Case #%d: %d" % (c['i'], a))

def main():
    c = read(sys.argv[1])
    for i in range(c['t']):
        solve(c[i])

if __name__ == "__main__":
    main()
