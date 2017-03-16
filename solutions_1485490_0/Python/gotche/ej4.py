import sys
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
def get_max_toys(toys,boxes):
    if not toys:
        return 0
    if not boxes:
        return 0
    keep_score = 0
    nt, tt = toys[0]
    discard_score = get_max_toys(toys[1:],boxes)
    for i, bx in enumerate(boxes):
        nb, tb = bx
        if tb==tt:
            created_boxes = min(nt,nb)
            if nt<nb:
                boxes = [(nb-nt,tb)] + boxes[i+1:]
                keep_score = created_boxes + get_max_toys(toys[1:], boxes)
                break
            elif nb<nt:
                keep_score = created_boxes + get_max_toys([(nt-nb,tb)]+toys[1:], boxes[i+1:])
                break       
            else:
                keep_score = created_boxes + get_max_toys(toys[1:],boxes[i+1:])
                break
    return max( discard_score, keep_score)


f = open(sys.argv[1],'r')
T = int(f.readline())
for case in xrange(T):
    N , M = [int(i)  for i in f.readline().strip().split(' ')]
    boxes = [int(i)  for i in f.readline().strip().split(' ')]
    boxes2=[]
    for j in xrange(N):
        boxes2.append((boxes[2*j],boxes[2*j+1]))
    toys = [int(i)  for i in f.readline().strip().split(' ')]
    toys2=[]
    for j in xrange(M):
        toys2.append((toys[2*j],toys[2*j+1]))
    print "Case #"+ str(case+1) + ": " + str(get_max_toys(boxes2,toys2))
