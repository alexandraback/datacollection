def rl():
    return fin.readline()
def r():
    return fin.read()
def w(o):
    print >>fout, o

def solve():
    T = int(rl())+1
    for t in xrange(1,T):
        S = rl().split()
        r = long(S[0])
        n = long(S[1])
        temp = r * r
        temp2 = (r+1) ** 2
        count = 0
        x = 2;
        tt = temp2 - temp
        while n >= tt:
            count += 1
            n -= tt
            temp = (r+x) ** 2
            temp2 = (r+x+1) ** 2
            tt = temp2 - temp
            x += 2
        w("Case #%d: %s" % (t,count))

fin = open('test.in', 'r')
fout = open('test.out', 'w')
solve()
fin.close()
fout.close()