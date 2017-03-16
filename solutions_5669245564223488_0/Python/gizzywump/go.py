#!/usr/bin/env python

import collections

import math
import re
import sys

INPUT = "tiny"
INPUT = "B-small-attempt7.in"
#INPUT = "B-large.in"

def debug(*args):
    #return
    sys.stderr.write(str(args) + "\n")

class Memoize:
    def __init__(self,function):
        self._cache = {}
        self._callable = function
            
    def __call__(self, *args, **kwds):
        cache = self._cache
        key = self._getKey(*args,**kwds)
        try: return cache[key]
        except KeyError:
            cachedValue = cache[key] = self._callable(*args,**kwds)
            return cachedValue
    
    def _getKey(self,*args,**kwds):
        return kwds and (args, ImmutableDict(kwds)) or args    


def fact(N):
    t = 1
    for i in range(1,N+1):
        t *= i
    return t


def collapse(car):
    s = car[0]
    for c in car[1:]:
        if c != s[-1]:
            s += c
    return s[0] + s[-1], frozenset(s[1:-1])
    

MOD = 1000000007
    

def do_trial(cars):
    car_pairs = [collapse(car) for car in cars]
    cars = [cp[0] for cp in car_pairs]
    internal_chars = set()
    for cp in car_pairs:
        internal_chars.update(cp[1])
    #import pdb; pdb.set_trace()
    # we have cars, internal_chars
    count = 1
    ind_cars = []
    # deal with cars that are all the same first
    cars.sort(key=lambda x: -len(set(x)))
    while len(cars) > 0:
        debug(cars, ind_cars, count)
        car = cars[-1]
        c0, c1 = car
        if c0 in internal_chars:
            return 0
        if c1 in internal_chars:
            return 0
        if c0 == c1:
            all_units = [c for c in cars if c == car]
            others = [c for c in cars if c != car]
            count *= fact(len(all_units))
            count %= MOD
            cars = others
            all_others = set()
            for o in others:
                all_others.update(o)
            if c0 not in all_others:
                ind_cars.append(car)
            continue
        cars = cars[:-1]
        for idx, car_1 in enumerate(cars):
            if car_1[0] == car_1[-1]:
                return 0
            if c1 == car_1[0]:
                # meld 'em
                cars = [(c0 + car_1[-1])] + cars[:idx] + cars[idx+1:]
                internal_chars.add(c1)
                break
            if car_1[-1] == c0:
                cars = [(car_1[0] + c1)] + cars[:idx] + cars[idx+1:]
                internal_chars.add(c0)
                break
        else:
            ind_cars.append(car)
            internal_chars.update(car)
    debug(cars, ind_cars, count)
    count *= fact(len(ind_cars))
    count %= MOD
    return count


f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    N, = (int(x) for x in f.readline().split())
    cars = f.readline().split()
    v = do_trial(cars)
    print "Case #%d: %s" % (i+1, v)
