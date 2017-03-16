T, F = True, False

class memoized(object):
   '''Decorator. Caches a function's return value each time it is called.
   If called later with the same arguments, the cached value is returned 
   (not reevaluated).
   '''
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
         # uncachable -- for instance, passing a list as an argument.
         # Better to not cache than to blow up entirely.
         return self.func(*args)
   def __repr__(self):
      '''Return the function's docstring.'''
      return self.func.__doc__
   def __get__(self, obj, objtype):
      '''Support instance methods.'''
      return functools.partial(self.__call__, obj)

@memoized
def f(ts, s, p, is_s):
    if not ts: return 0

    t, ts = ts[0], ts[1:]

    q, r = divmod(t, 3)

    if t == 0:
        x, y, z = 0, 0, 0
        s += is_s
    else:
        if is_s:
            if r == 0:
                x, y, z = q - 1, q, q + 1
            elif r == 2:
                x, y, z = q, q, q + 2
            else:
                # not actually is_s
                x, y, z = q, q, q + 1
                s += 1
        else:
            q2 = q + (r == 2)
            x, y, z = q2, q2, t - q2 * 2

    if s == 0:
        return (x >= p or y >= p or z >= p) + f(ts, s, p, F)
    return (x >= p or y >= p or z >= p) + max(
        f(ts, s - 1, p, T),
        f(ts, s, p, F)
    )


def calc_possibilities(ts, s, p):
    if s == 0:
        return f(ts, s, p, F)

    return max(f(ts, s - 1, p, T),
               f(ts, s, p, F))

for i in xrange(1, int(raw_input()) + 1):
    parts = [ int(x) for x in raw_input().split(" ") ]
    _ = parts[0]
    s = parts[1]
    p = parts[2]

    ts = tuple(parts[3:])

    p = calc_possibilities(ts, s, p)
    print "Case #{0}: {1}".format(i, p)

