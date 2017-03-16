import sys

import collections
import functools

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

@memoized
def adjust_motes(arvin_size, other_motes, ops=0):
    #Eat motes until we can't
    for i, mote in enumerate(other_motes):
        if arvin_size > mote:
            arvin_size += mote
        else:
            #Either remove the next node, or add the biggest size node we can
            #Edge case - we have a size of 1, we can only remove
            if arvin_size == 1:
                return adjust_motes(arvin_size, other_motes[i + 1:], ops + 1)
            else:
                return min(adjust_motes(arvin_size, other_motes[i + 1:], ops + 1),
                           adjust_motes(arvin_size + arvin_size - 1,
                                        other_motes[i:], ops + 1))

    return ops

if __name__ == '__main__':
    data = [line.strip() for line in sys.stdin]
    for case in range(int(data[0])):
        arvin_size = int(data[case * 2 + 1].split()[0])
        other_motes = [int(size) for size in data[case * 2 + 2].split()]
        other_motes.sort()
        print "Case #%d: %d" % (case + 1, adjust_motes(arvin_size, tuple(other_motes)))
