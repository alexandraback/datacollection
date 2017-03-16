#!/usr/env/python

from sys import stdin

def resolv():
    input = [float(i) for i in stdin.readline().strip().split()]
    time_passed = 0
    production = 2.0
    farm_price = input[0]
    farm_prod = input[1]
    target = input[2]
    while True:
        time_without_farm = target / production
        farm_cost = farm_price / production
        time_with_farm = farm_cost + (target / (production + farm_prod))
        if time_without_farm > time_with_farm:
            time_passed = time_passed + farm_cost
            production = production + farm_prod
        else:
            return time_passed + time_without_farm

nb = int(stdin.readline().strip())
for i in range(1, nb + 1):
    print('Case #{}: {}'.format(i, resolv()))
