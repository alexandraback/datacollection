
fi = open("input.txt", "r")
fo = open("output.txt", "w")

def solve():
    r, c, w = map(int, fi.readline().strip().split(' '))
    if w == 1: return r * c
    cc = c / w
    li = (cc * w)
    b = w - 1
    a = min(w - 1, c - li)
    return r * cc + min(b + a, w)

if __name__ == "__main__":
    t = int(fi.readline().strip())
    for tt in xrange(1, t + 1):
        ans = solve()
        print "Case #%d: %d" % (tt, ans)
        print >>fo, "Case #%d: %d" % (tt, ans)

fo.close()
