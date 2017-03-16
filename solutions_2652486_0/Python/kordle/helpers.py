# helpers for code jam


class memoize:
    def __init__(self, f):
        self.f = f
        self.memo = {}
    def __call__(self, *args):
        if not args in self.memo:
            self.memo[args] = self.f(*args)
        return self.memo[args]


from fractions import gcd
from collections import defaultdict


alphabet = 'abcdefghijklmnopqrstuvwxyz'

def todigits(num, base=10):
    ret = []
    while num > 0:
        num, r = divmod(num, base)
        ret.insert(0,r)
    return ret


def fromdigits(digs, base=10):
    ret = 0
    for d in digs:
        ret *= base
        ret += d
    return ret

    


def nextline(f):
    return f.readline().replace('\n','').strip()

def intline(f):
    line = nextline(f)
    
    return [int(n) for n in line.split(' ')]

def firstint(f):
    return intline(f)[0]
