import time
import os
import sys
import itertools
import functools
import math

# ----------------------------------------------------------------------

def read_ints(fd):
    return [int(p) for p in fd.readline().strip().split()]

def read_floats(fd):
    return [float(p) for p in fd.readline().strip().split()]

class memoizeit(object):
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
            return self.func(*args)
    
    @property
    def __name__(self):
        return self.func.__name__
    
    def __get__(self, obj, objtype):
        return functools.partial(self.__call__, obj)

class timeit(object):
    def __init__(self, func):
        self.func = func
    def __call__(self, *args):
        start = time.time()
        value = self.func(*args)
        delta = time.time() - start
        print self.func.__name__, "{:7.3f}s, (res: {})".format(delta, value)
        return value
    def __get__(self, obj, objtype):
        return functools.partial(self.__call__, obj)

# ----------------------------------------------------------------------

def read_input(filename):
    data = []
    with open(filename, "r") as f:
        cases = read_ints(f)[0]
        # =============================================
        for _ in xrange(cases):
            params = read_ints(f)
            data.append( params[1:])

        # =============================================
    return data

def make_output(fname, output):
    CASE_PRFX = "Case #%s: "
    fname = fname + time.strftime("%H%M%S") + ".out"
    with open(fname, "w") as f:
        # =============================================
        restext = []
        for i, v in enumerate(output):
            restext.append(CASE_PRFX % (i+1,) + "\n")
            if v is None:
                restext.append("Impossible")
            else:
                restext.append(" ".join([str(i) for i in v[0]]) + "\n")
                restext.append(" ".join([str(i) for i in v[1]]) + "\n")
        f.writelines(restext)
        # =============================================

@timeit
def main(fname):
    data = read_input(fname)
    output = []
    for i, case in enumerate(data):
        res = solveit(case)
        output.append(res)
    make_output(fname, output)


# ----------------------------------------------------------------------

@timeit
def solveit(case):
    sums = {}
    for n in xrange(len(case)):
        for m in itertools.combinations(case, n):
            s = sum(m)
            if s in sums.keys():
                return (sums[s], m)
            else:
                sums.setdefault(s, m)
    return None
        
# ----------------------------------------------------------------------

#main("ex.in")
main("C-small-attempt0.in")
#main("large.in")

