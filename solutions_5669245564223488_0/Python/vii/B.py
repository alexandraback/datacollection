import sys
from collections import *

def r():
    return sys.stdin.readline().rstrip()


T = int(r())

def fact(n):
    if n <= 1:
        return 1
    return n * fact(n - 1)

def solve():
    N = int(r())
    cars = r().split(" ")
    starting = {}
    ending = {}
    monoletter = defaultdict(list)
    for c in cars:
        mono = True
        for l in c:
            if l != c[0]:
                mono = False
                break

        if mono:
            monoletter[c[0]].append(c)
        else:
            if c[0] == c[-1]:
                return 0
            if c[0] in starting:
                return 0
            starting[c[0]] = c
            if c[-1] in ending:
                return 0
            ending[c[-1]] = c

    all_joined_letters = set(starting.keys() + ending.keys() + monoletter.keys())
    
    for l in all_joined_letters:
        for c in starting.values():
            if l in c.lstrip(c[0]).rstrip(c[-1]):
                return 0

    count = 1
    new_cars = []
    for l in all_joined_letters:
        m = monoletter.get(l, list())
        mono_joined = "".join(m)
        count *= fact(len(m))
        monoletter[l] = list()
        
        new_car = mono_joined
        if l in starting:
            if starting[l] == False:
                return 0
            new_car = new_car + starting[l]
            starting[l] = False

        if l in ending:
            if ending[l] == False:
                return 0
            new_car = ending[l] + new_car
            ending[l] = False
        
        ending[new_car[-1]] = new_car
        starting[new_car[0]] = new_car
        if len(new_car.lstrip(new_car[0])) > 0 and new_car[-1] == new_car[0]:
            return 0
    
    return count * fact(len([e for e in ending.values() if e != False]))

for t in range(1, T+1):
    print("Case #%d: %s" %( t, solve()))
