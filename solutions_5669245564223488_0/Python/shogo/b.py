T = int(raw_input())

import re

first = re.compile(r'^([a-z])\1*')
last = re.compile(r'([a-z])\1*$')

MOD = 1000000007

def fraction(n):
    ans = 1
    for i in range(n):
        ans = (ans * (i + 1)) % MOD
    return ans

def count(cars_map, last_ch, rest, seen):
    if rest == 0:
        return 1

    ans = 1
    m = {}
    if last_ch in cars_map:
        m = cars_map[last_ch]

    if last_ch in m:
        ans = fraction(m[last_ch])
        rest -= m[last_ch]
    if rest == 0:
        return ans

    seen = dict(seen)
    seen[last_ch] = 1

    keys = [k for k in m.keys() if k != last_ch]
    if len(keys) > 0:
        if len(keys) > 1: return 0
        ans = 1
        k = keys[0]
        if k in seen: return 0
        rest -= 1
        cars_map[last_ch] = {}
        ans = (ans * count(cars_map, k, rest, seen)) % MOD
        cars_map[last_ch] = m
        return ans
    else:
        cars_map[last_ch] = {}
        cnt = 0
        for ch in cars_map.keys():
            if len(cars_map[ch].keys()) == 0: continue
            cnt = (cnt + count(cars_map, ch, rest, seen)) % MOD
        cars_map[last_ch] = m
        return (ans * cnt) % MOD

def strip(s):
    return last.sub('', first.sub('', s))

def calc(cars):
    alone = []
    for c in cars:
        s = strip(c)
        alone.append(s)
        if s != '' and c[0] == c[-1]: return 0
    alone_map = {}
    for c in alone:
        if c == '': continue
        last_ch = ''
        for ch in c:
            if last_ch != ch and ch in alone_map: return 0
            alone_map[ch] = 1
            last_ch = ch

    car_map = {}
    for c in cars:
        if c[0] in alone_map: return 0
        if c[-1] in alone_map: return 0
        if c[0] not in car_map:
            car_map[c[0]] = {}
        if c[-1] not in car_map[c[0]]:
            car_map[c[0]][c[-1]] = 0
        car_map[c[0]][c[-1]] += 1

    return count(car_map, ' ', len(cars), {}) % MOD

import sys

for t in range(T):
    N = int(raw_input())
    cars = raw_input().split()
    #print cars
    print "Case #{0}: {1}".format(t + 1, calc(cars))
    sys.stdout.flush()
