
def check (m, key, k):
    return (not m.has_key(key)) or m[key] < k

def inc_value(k, key):
    if m.has_key(key):
        m[key] += 1
    else:
        m[key] = 1

t = int(raw_input())
for i in xrange(1, t + 1):
    m = {}
    rv = []
    line = raw_input()
    #print line
    [j, p, s, k] = map(lambda x: int(x), line.split(' '))
    days = j*p*min(s, k)
    for a in range(1, j+1):
        for b in range(1, p+1):
            for c in range(1, s+1):
                k1 = "%d %d 0" % (a, b)
                k2 = "%d 0 %d" % (a, c)
                k3 = "0 %d %d" % (b, c)
                if check(m, k1, k) and check(m, k2, k) and check(m, k3, k):
                    inc_value(m, k1)
                    inc_value(m, k2)
                    inc_value(m, k3)
                    rv.append([a, b, c])
    print("Case #{}: {}".format(i, len(rv)))
    for l in rv:
        print ("{} {} {}".format(l[0], l[1], l[2]))

