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
for x in xrange(1, count + 1):
    a = tuple(map(int, lines[x].split()))
    results.append(a)


def count_recycled(num, minval, maxval):
    r = 0
    q = s = str(num)
    q = q[len(q)-1] + q[:-1]
    while q != s:
        if int(q) >= minval and int(q) <= num and not q.startswith('0'):
            r += 1
        q = q[len(q)-1] + q[:-1]
    return r

i = 1
for a, b in results:
    r = 0
    for x in xrange(a, b + 1):
        r += count_recycled(x, a, b)
    print "Case #%d: %d" % (i, r)
    i += 1
