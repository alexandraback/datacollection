#!/usr/env/python

from sys import stdin

def resolv_rec(time_passed, production, farm_price, farm_prod, target):
    while True:
        time_without_farm = target / production
        farm_cost = farm_price / production
        time_with_farm = farm_cost + (target / (production + farm_prod))
        if time_without_farm > time_with_farm:
             time_passed = time_passed + farm_cost
             production = production + farm_prod
        else:
            return time_passed + time_without_farm

def resolv():
    input = [float(i) for i in stdin.readline().strip().split()]
    return resolv_rec(0.0, 2.0, input[0], input[1], input[2])

nb = int(stdin.readline().strip())
for i in range(1, nb + 1):
    print('Case #{}: {}'.format(i, resolv()))
