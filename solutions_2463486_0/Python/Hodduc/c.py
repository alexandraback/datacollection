import bisect
n = input()

db = []

def palin(x):
    return str(x) == ''.join(reversed(str(x)))

for x in xrange(1, 10000001):
    o=x*x
    if palin(x) and palin(o):
        db.append(o)

for i in range(1, n+1):
    def process():
        n, m = map(int, raw_input().split())
        x = bisect.bisect_left(db,n)
        y = bisect.bisect_right(db,m)
        return y-x

    print "Case #%d:" % i, process()
