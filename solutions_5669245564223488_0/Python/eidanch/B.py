# -*- coding: utf-8 -*-
"""
Created on Sun May 11 12:24:20 2014

@author: eidanch
"""

from itertools import permutations

def get_line():
    return raw_input().strip()

formatIntegerList = lambda s: list(map(int,s.split(' ')))

def standard_input():
    T = int(get_line())
    for i in range(T):
        N = int(get_line())
        lst = get_line().split(' ')
        yield (i+1,lst)


def validate_adj_letter(l, train):
    state = 0
    for c in train:
        if state == 0 and l == c:
            state = 1
        elif state == 1 and l != c:
            state = 2
        elif state == 2 and l == c:
            return False
    return True

def handle_case2(case):
    cars = case
    for i in range(len(cars)):
        cars[i] = shorten_car(cars[i])
        if cars[i] is None:
            return str(0)
    count = 0
    letters = set(c for s in cars for c in s)
    for perm in permutations(cars):
        valid = True
        for l in letters:
            train = ''.join(perm)
            if not validate_adj_letter(l,train):
                valid = False
                break
        if valid:
            count += 1
            
    return str(count)
    
def shorten_car(s):
    result = ''
    for i in range(len(s)):
        if s[i] not in result:
            result += s[i]
        elif i > 0 and s[i] != s[i-1]:
            return None
    return result
    
def build_path(cars, car,last, mcars, deps):
    after = [car2 for car2 in cars if (last,car2) in deps]
    #print after
    if len(after) > 1:
        return None
    elif len(after) == 1:
        car2 = after[0]
        if car2 not in cars:
            return None
        cars.remove(car2)
        if car2 in mcars:
            mcars.remove(car2)
        car += car2
        return build_path(cars, car,car2, mcars, deps)
    elif len(after) == 0:
        return car
    
def fact(x):
    result = 1
    for i in range(2, x+1):
        result *= x
    return result

def handle_case(case):
    cars = case
    lencars = len(cars)
    for i in range(len(cars)):
        cars[i] = shorten_car(cars[i])
        if cars[i] is None:
            return str(0)
    letters = set(c for s in cars for c in s)
    for l in letters:
        if len([s for s in cars if l in s[1:-1]]) >= 1 \
            and len([s for s in cars if l in s]) >= 2:
            return '0'
    ldict = dict()
    for l in letters:
        ldict[l] = 0
    for car in cars:
        if car in letters:
            ldict[car] += 1
    cars = list(set(cars))
    deps = list()
    for car1 in cars:
        for car2 in cars:
            if car1[-1] == car2[0] and car1 != car2:
                deps.append((car1,car2))
    mcars = list()
    for car in cars:
        if car in cars:
            ncar = build_path(cars, car,car, mcars, deps)
            if ncar is None:
                return '0'
            mcars.append(ncar)
    #print mcars, deps
    #print lencars, len(mcars)
    tcount = 1
    for k,v in ldict.iteritems():
        tcount *= fact(v)
    return str(fact(len(mcars))*tcount)
    
        
def main():
    for i,case in standard_input():
        print "Case #%d: %s" %(i,handle_case(case))        

if __name__ == '__main__':
    main()
    