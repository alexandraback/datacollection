#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
"""

import math
# import sys
# sys.setrecursionlimit(10000)

def trim_doubles(cars):
    def trim_d(car):
        old = '.'
        ret = ''
        for c in car:
            if c != old:
                old = c
                ret += c
        return ret

    return map(trim_d, cars)

def isolated_letter(cars):
    ls = {}
    for car in cars:
        if len(car) > 2:
            for c in car[1:-1]:
                ls[c] = ls.get(c, 0) + 1
    return ls

def exclusive_start_end(cars):
    start = {}
    end = {}
    for car in cars:
        if len(car) > 1:
            start[car[0]] = start.get(car[0], 0) + 1
            end[car[-1]] = end.get(car[-1], 0) + 1
    return start, end

def mono_letter(cars):
    mono = {}
    new_cars = []
    for car in cars:
        if len(car) == 1:
            mono[car[0]] = mono.get(car[0], 0) + 1
            # if mono[car[0]] == 1:
            #     new_cars.append(car)
        else:
            new_cars.append(car)
    return new_cars, mono

def glue_first(car, cars):
    end_with = car[-1]
    start_with = car[0]
    for i in range(len(cars)):
        if cars[i][0] == end_with:
            cars[i] = car[:-1] + cars[i]
            return cars, True
        if cars[i][-1] == start_with:
            cars[i] = cars[i][:-1] + car
            return cars, True
    cars.append(car)
    return cars, False

def place_forced(cars):
    flag2 = True
    while flag2:
        flag2 = False
        for i in range(len(cars)):
            car = cars.pop(0)
            cars, flag = glue_first(car, cars)
            if flag:
                flag2 = True
    return cars

def count_letters(cars):
    l = {}
    for car in cars:
        for c in car:
            l[c] = l.get(c, 0) + 1
    return l

def solve(cars):
    old_cars = cars
    cars = trim_doubles(cars)
    cars, mono = mono_letter(cars)
    ls = isolated_letter(cars)
    start, end = exclusive_start_end(cars)
    # print '-------'
    # print 'old_cars: ', old_cars
    # print 'cars: ', cars
    # print 'mono: ', mono
    # print 'ls: ', ls
    # print 'start: ', start
    # print 'end: ', end
    if max(ls.values() + [0]) > 1: # impossible
        return 0
    if max(start.values() + [0]) > 1: # impossible
        return 0
    if max(end.values() + [0]) > 1: # impossible
        return 0
    cars = place_forced(cars)
    # print 'forced: ', cars
    letters = count_letters(cars)
    # print 'letters: ', letters
    if max(letters.values() + [0]) > 1: # impossible
        return 0
    possibilities = 1
    more = len(cars)
    isolated_in_letters = []
    for iso, nb in mono.items():
        # print '==iso: ', iso
        if iso not in letters:
            # print '====iso if: ', iso
            more += 1
        possibilities *= math.factorial(nb)
    # print 'more: ', more
    possibilities *= math.factorial(more)
    return possibilities % 1000000007
    

def main():
    T = int(raw_input())
    for i in range(1, T + 1):
        N = raw_input()
        cars = raw_input().split()
        res = solve(cars)
        print "Case #{}: {}".format(i, res)

def test():
    pass

if __name__ == '__main__':
    # test()
    main()
