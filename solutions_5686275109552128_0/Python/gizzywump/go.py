#!/usr/bin/env python

import collections

import math
import re
import sys

#sys.setrecursionlimit(50)

INPUT = "tiny"
INPUT = "B-small-attempt2.in"

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

def do_trial(S):
    distribution = [0] * (max(S) + 1)
    for s in S:
        distribution[s] += 1
    minutes = 0
    best_size = int(1e8)
    while len(distribution) > 0:
        best_size = min(best_size, minutes + len(distribution) - 1)
        if minutes >= best_size:
            break
        if distribution[-1] == 0:
            distribution = distribution[:-1]
            continue
        most_cakes = len(distribution) - 1
        debug("%s: most_cakes is %d, %d minutes, best solution %d" % (distribution, most_cakes, minutes, best_size))
        if distribution[-1] >= most_cakes:
            # too big... just wait that many minutes
            minutes += most_cakes
            break
        s1, s2 = (most_cakes + 1) // 2, most_cakes // 2
        distribution[s1] += distribution[most_cakes]
        distribution[s2] += distribution[most_cakes]
        minutes += distribution[most_cakes]
        distribution[most_cakes] = 0
        
    return best_size

def do_trial(S):
    distribution = [0] * (max(S) + 1)
    for s in S:
        distribution[s] += 1
    best_time = 10000
    current_time = 0
    while 1:
        if len(distribution) == 0:
            return best_time
        if distribution[-1] == 0:
            distribution = distribution[:-1]
            continue
        if current_time >= best_time:
            return best_time
        most_pancakes = len(distribution) - 1
        best_time = min(best_time, current_time + most_pancakes)
        redistributed = distribution[-1]
        current_time += redistributed
        p1 = most_pancakes//2
        p2 = (most_pancakes+1)//2
        distribution[p1] += redistributed
        distribution[p2] += redistributed
        distribution[-1] = 0


def do_trial(S):
    distribution = [0] * (max(S) + 1)
    for s in S:
        distribution[s] += 1
    #import pdb; pdb.set_trace()
    return best_time(tuple(distribution))


def best_time(distribution, give_up_time=100000):
    debug(distribution, give_up_time)
    if len(distribution) == 0:
        return 0
    if distribution[-1] == 0:
        return best_time(distribution[:-1], give_up_time)
    most_pancakes = len(distribution) - 1
    if most_pancakes == 1:
        return 1
    just_eat_time = most_pancakes
    if just_eat_time > give_up_time:
        return just_eat_time
    plate_count_to_redistribute = distribution[-1]
    p1 = most_pancakes//2
    p2 = (most_pancakes+1)//2
    distribution[p1] += plate_count_to_redistribute
    distribution[p2] += plate_count_to_redistribute
    return min(plate_count_to_redistribute+best_time(distribution[:-1], just_eat_time), just_eat_time)


#@Memoize
def best_time(distribution):
    debug("dist = %s" % str(distribution))
    #import pdb; pdb.set_trace()
    # handle all pancakes gone
    if len(distribution) <= 1:
        return 0
    # no one has len(distribution) - 1 pancakes
    if distribution[-1] == 0:
        return best_time(distribution[:-1])
    # not a special minute
    d = [0] + list(distribution[2:])
    time_for_unspecial = 1 + best_time(tuple(d))
    # is a special minute (and so are the next distribution[-1])
    plate_count_to_redistribute = distribution[-1]
    if plate_count_to_redistribute >= time_for_unspecial:
        return time_for_unspecial
    distribution = list(distribution)
    most_pancakes = len(distribution) - 1
    p1 = most_pancakes//2
    p2 = (most_pancakes+1)//2
    distribution[p1] += plate_count_to_redistribute
    distribution[p2] += plate_count_to_redistribute
    time_for_special = plate_count_to_redistribute + best_time(tuple(distribution[:-1]))
    return min(time_for_special, time_for_unspecial)


f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    N = int(f.readline()[:-1])
    S = [int(x) for x in f.readline().split()]
    v = do_trial(S)
    print "Case #%d: %s" % (i+1, v)
