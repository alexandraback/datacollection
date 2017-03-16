from sys import stdin
import collections
import functools

DEBUG = False

class memoized(object):
   '''Decorator. Caches a function's return value each time it is called.
   If called later with the same arguments, the cached value is returned
   (not reevaluated).
   '''
   def __init__(self, func):
      self.func = func
      self.cache = {}
   def __call__(self, *args):
      if not isinstance(args, collections.Hashable):
         # uncacheable. a list, for instance.
         # better to not cache than blow up.
         return self.func(*args)
      if args in self.cache:
         return self.cache[args]
      else:
         value = self.func(*args)
         self.cache[args] = value
         return value
   def __repr__(self):
      '''Return the function's docstring.'''
      return self.func.__doc__
   def __get__(self, obj, objtype):
      '''Support instance methods.'''
      return functools.partial(self.__call__, obj)

def debug_print(*args):
    if DEBUG:
        print args

def main():
    num_cases = int(stdin.readline())
    for case in range(1, num_cases + 1):
        S = stdin.readline().strip()

        best_word = generate_best_word(S[1:], S[0])

        print "Case #{}: {}".format(case, best_word)

@memoized
def generate_best_word(S, w):
    # w is word already built up
    if S == '':
        return w

    best1 = generate_best_word(S[1:], S[0] + w)
    best2 = generate_best_word(S[1:], w + S[0])

    return sorted([best1, best2])[1]

if __name__ == "__main__":
    main()
