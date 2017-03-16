import numpy
import sys

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
        c['x'],c['y'] = map(int, l.pop().split())
        r[i] = c
    return r

def subsolve(p, j, inc, dec):
    if p < 0:
        tv = inc
        inc = dec
        dec = tv
        p = -1 * p

    r = []
    s = 0
    while  s+j <= p:
        s += j
        j += 1
        r.append(inc)
    
    t = p - s
    for i in range(t):
        r.extend([dec,inc])
        j += 2
    return (r,j)


def solve(c):
    x = c['x']
    y = c['y']

    j = 1
    rx,j = subsolve(x, j, "E", "W")
    ry,j = subsolve(y, j, "N", "S")
    


    print("Case #%d: %s" % (c['i'], "".join(rx+ry)))

def main():
    c = read(sys.argv[1])
    for i in range(c['t']):
        solve(c[i])

if __name__ == "__main__":
    main()
