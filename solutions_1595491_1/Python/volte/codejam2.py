import sys
import math

class memoize(object):
    """A decorator that caused a function to cache its result to avoid repeated
    computation.
    """
    def __init__(self, func):
        self.func = func
        self.cache = {}

    def __call__(self, *args):
        try:
            return self.cache[args]
        except KeyError:
            value = self.func(*args)
            self.cache[args] = value
            return value
        except TypeError:
            # We can't use these arguments as a key, so don't cache
            return self.func(*args)

lines = []
with open(sys.argv[1]) as f:
    lines = f.readlines()

count = int(lines[0])
results = []
for x in xrange(1,count+1):
    a = tuple(map(int, lines[x].split()))
    results.append((a[1], a[2], a[3:]))

@memoize
def check(s, p, ts):
    if len(ts) == 0: return 0
    t = ts[0]
    b = math.floor(t / 3.0)
    z = t - b
    a = math.ceil(z / 2.0)
    c = math.floor(z / 2.0)
    q = list(sorted([a,b,c]))
    qq = q
    if q[1] > 0: qq = [q[0], q[1]-1, q[1]+1]

    if a >= p or b >= p or c >= p:
        return check(s, p, ts[1:]) + 1
    elif s > 0 and (qq[0] >= p or qq[1] >= p or qq[2] >= p):
        return max(check(s, p, ts[1:]), check(s-1, p, ts[1:]) + 1)

    return check(s, p, ts[1:])

i = 1
for r in results:
    s = r[0]; p = r[1]; ts = r[2:]
    print "Case #%d: %d" % (i, check(s, p, ts[0]))
    i += 1

