
import sys

def add_coin(c, vs, v):
    for i in xrange(v, 0, -1):
        if vs[i] and (i + c) <= v:
            vs[i + c] = True
    vs[c] = True

def solve(cs, v):
    vs = [ False ] * (v + 1)
    for c in cs:
        add_coin(c, vs, v)
    count = 0
    # print vs
    for i in xrange(1, v + 1):
        if vs[i] == False:
            count += 1
            add_coin(i, vs, v)
    return count


if __name__ == '__main__':

    lines = sys.stdin.readlines()
    T = int(lines[0].strip())
    
    for i in xrange(T):
        c, d, v = map(int, lines[2*i+1].split())
        assert c == 1
        cs = map(int, lines[2*i+2].split())
        x = solve(cs, v)
        print "Case #%d: %d" % (i+1, x)
