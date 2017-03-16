from itertools import permutations
from multiprocessing import Pool
import math

def check(cars):
    seenChars = set(cars[0][0])
    lastSeen = cars[0][0]
    ccars = ""
    for c in cars:
        ccars += c
    for char in ccars:
        if char != lastSeen:
            if char in seenChars:
                return False
            else:
                seenChars.add(char)
                lastSeen = char
    return True

pool = Pool(processes=8)

for T in range(1, input()+1):
    # parse input
    N = input()
    cars = raw_input().split()
    new_cars = []
    for c in cars:
        newc = c[0]
        lastChar = c[0]
        for char in c:
            if char != lastChar:
                lastChar = char
                newc += char
        new_cars.append(newc)
    cars = new_cars



    letters = {x:set() for x in 'abcdefghijklmnopqrstuvwxyz'}
    for i in range(len(cars)):
        for char in cars[i]:
            letters[char].add(i)
    maxl = 0
    for l in letters.keys():
        maxl = max(maxl, len(letters[l]))
    if maxl == 1:
        if check(cars):
            res = math.factorial(len(cars))
        else:
            res = 0
    else:
        res = 0
        if len(cars) > 5:
            vals = pool.map(check, permutations(cars))
            res = vals.count(True)
        else:
            for c in permutations(cars):
                if check(c):
                    res += 1

    res = res%1000000007

    print "Case #" + str(T) + ": " + str(res)