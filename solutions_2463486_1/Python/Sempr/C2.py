import sys
res = []

def valid(x):
    s = str(x)
    if s == s[::-1]: return True
    else: return False

def build():
    for i in xrange(1,10000):
        v = str(i)
        a,b = v + v[::-1], v + v[::-1][1:]
        va = long(a)
        vt = va*va
        if valid(vt): res.append(vt)
        vb = long(b)
        vt = vb*vb
        if valid(vt): res.append(vt)


def main():
    T = sys.stdin.readline()
    T = int(T)
    for i in xrange(T):
        l = sys.stdin.readline()
        A,B = tuple([long(x) for x in l.split()][:2])
        print "Case #%d: %d" % (i+1, len([x for x in res if A<=x<=B]))

if __name__ == '__main__':
    build()
    main()

