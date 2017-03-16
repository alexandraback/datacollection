import sys,math

import collections
import functools

# https://wiki.python.org/moin/PythonDecoratorLibrary#Memoize
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
    def __name__(self):
        return self.func.__name__
    def __repr__(self):
        return self.func.__repr__
    def __doc__(self):
        return self.func.__doc__
    def __get__(self, obj, objtype):
        '''Support instance methods.'''
        return functools.partial(self.__call__, obj)

class debugged(object):
    def __init__(self,func):
        self.func = func
        
    def __call__(self,*args):
        print("[{}({}) = ? ".format(self.func.__name__,args),file=sys.stderr)
        val = self.func(*args)
        print("{}({}) = {}]".format(self.func.__name__,args,val),file=sys.stderr)
        return val

def main_small(D,P):
    P.sort()
    P.reverse()
    Pin = tuple(P)

    @memoized
    #@debugged
    def aux(P):
        p = P[0]
        if p <= 2:
            return p
        else:
        # PP1 = [pp - 1 for pp in P];
        # v1 = main_small(D,PP1);
            res = P[0]-1
            for i in range(p//2,p):
                PP = list(P)
                PP[0] = i
                PP.append(p - i)
                PP.sort()
                PP.reverse()
                PPin = tuple(PP)
                v2 = aux(PPin)
                res = min(res,v2)
            return res+1

    return aux(Pin);

if __name__ == "__main__":
    T = int(input())
    for c in range(T):
        D = int(input())
        P = [int(i) for i in input().split()]
        res = main_small(D,P)
        #res = main_large(smax,si)
        print("Case #{}: {}".format(c+1,res),file=sys.stderr)
        print("Case #{}: {}".format(c+1,res))
