# Round 1B 2015
# Problem A. Counter Culture
# MichelJ

import sys
import logging
import StringIO
from itertools import chain

def echo(fn):
    def wrapped(*v, **k):
        name = fn.__name__
        logging.info( "Called %s(%s)" % (name, ", ".join(map(repr, chain(v, k.values())))) )
        res = fn(*v, **k)
        logging.info( "       %s(%s) returned %s" % (name, ", ".join(map(repr, chain(v, k.values()))),res) )
        return res
    return wrapped

class memoized(object):
   """Decorator that caches a function's return value each time it is called.
   If called later with the same arguments, the cached value is returned, and
   not re-evaluated.
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
         # uncachable -- for instance, passing a list as an argument.
         # Better to not cache than to blow up entirely.
         return self.func(*args)
   def __repr__(self):
      """Return the function's docstring."""
      return self.func.__doc__
   def __get__(self, obj, objtype):
      """Support instance methods."""
      return functools.partial(self.__call__, obj)


def rev(x):
    s = str(x)[::-1]
    return int(s)

def solve(N):
    a = [2000000000 for i in xrange(1000001)]
    a[1] = 1
    for i in xrange(1,N):
        a[i+1] = min(a[i+1], a[i]+1)
        ir = rev(i)
        if a[i]+1 < a[ir]:
            a[ir] = a[i]+1
#            if a[i]+1 < a[ir]:
#                a[ir] = a[i]+1
#    print a[1:N+1]
    return str(a[N])

def solve2(N):
    if N < 21:
        return N
    s = str(N)
    dl = int(s[-1])
    if dl == 0:
        return solve2(N - 1) + 1
    n = len(s)
    n2 = n // 2
    d11 = int(s[:n2])
    min10 = int('1' + (n2-1)*'0')
    if d11 > min10:
        dll = int(s[-n2:])
        return dll + solve2(rev(N - dll + 1))
    N99 = int((len(s)-1)*'9')
    return int(s[1:]) + 1 + solve2(N99)
    
def main(data=None):
    if data is not None:
        sys.stdin = StringIO.StringIO(data)
    for tc in xrange(1, int(raw_input()) + 1):
        N = int(raw_input())
        print 'Case #%d: %s' % (tc, solve2(N))
    if data is not None:
        sys.stdin = sys.__stdin__

sample="""3
1
19
23
"""


# Call main() only if run from command line, not from IDLE
if __name__ == "__main__":
    if True:
#    if '/' not in sys.argv[0] and '\\' not in sys.argv[0]:
        logging.basicConfig(level=logging.INFO)
        sys.exit(main())
    else:
        logging.basicConfig(level=logging.INFO,format=" %(levelname)s: %(message)s")
