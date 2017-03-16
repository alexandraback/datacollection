
t = int(raw_input())


def solve(pt, fin_val, tot):
    tmp = (fin_val - pt) * 100 / tot
    return tmp if tmp > 0 else 0

for i in xrange(t):
    tmp = map(int, raw_input().split())
    n, p = tmp[0], tmp[1:]

    tot = sum(p)
    avg = tot*1.0/n

    newp = [pt for pt in p if pt < 2* avg]
    newtot = sum(newp)
    newavg = newtot * 1.0/ len(newp)


    fin_val = newavg + tot * 1.0 / len(newp)
    res = []
    for pt in p:
        res.append( "%f" % solve(pt, fin_val, tot) )
    print "Case #%s: %s" % (i+1, " ".join(res))
