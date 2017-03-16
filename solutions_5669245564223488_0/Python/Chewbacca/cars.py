#! /usr/bin/env python3
import sys
# (c) Krzysztof 'Chris' Leszczynski
# Please don't think I write programs in this way.
# I am in hurry, this is code jam, you know.
# Anyway, if you think you spotted a bug, send me a line
# to chris@camk.edu.pl

twos = [ (1<<_) for _ in range(50) ]

def GCD(a,b):
    a, b = abs(a), abs(b)
    a, b = max(a,b), min(a,b)
    while True:
        if b==0:
            return a
        a, b = b, a%b

def remove_duplicates(s):
    last_char = 'whatever'
    s1 = ''
    for ch in s:
        if last_char != ch:
            s1 += ch
            last_char = ch
    return s1


def empty_list():
    # sorry, i don't know python
    return list(range(0))

def solve(cars):
    # remove multiples 'aaabbbbbcccc' -> 'abc'
    cars=map(remove_duplicates,cars)
    insiders = {}
    for car in cars:
        if len(car)>2:
            for ch in car[1:-1]:
                if ch in insiders:
                    return 0
                insiders[ch]=1
    for car in cars:
        if car[0] in insiders or car[-1] in insiders:
            return 0
    cars = list(map((lambda x: (x[0],x[-1])),cars))
    return solve_small(cars)


    left = {}
    right = {}
    for i,car in enumerate(cars):
        left[car[0]] = left.get(car[0],empty_list) + [i]
        right[car[1]] = left.get(car[1],empty_list) + [i]
    cluster = []
    leftleft = None;
    for l in left:
        le = len(left[l])
    #  tooo hard right now, doing small instead :-(



## Stolen from http://stackoverflow.com/questions/104420/how-to-generate-all-permutations-of-a-list-in-python
## and edited because it's python3-buggy
def permutations(iterable, r=None):    
    # permutations('ABCD', 2) --> AB AC AD BA BC BD CA CB CD DA DB DC
    # permutations(range(3)) --> 012 021 102 120 201 210
    pool = tuple(iterable)
    n = len(pool)
    r = n if r is None else r
    if r > n:
        return
    indices = list(range(n))
    cycles = list(range(n, n-r, -1))
    yield tuple(pool[i] for i in indices[:r])
    while n:
        for i in reversed(range(r)):
            cycles[i] -= 1
            if cycles[i] == 0:
                indices[i:] = indices[i+1:] + indices[i:i+1]
                cycles[i] = n - i
            else:
                j = cycles[i]
                indices[i], indices[-j] = indices[-j], indices[i]
                yield tuple(pool[i] for i in indices[:r])
                break
        else:
            return


def solve_small(cars):
    L = len(cars)
    cnt = 0
    for train in permutations(cars):
        found = {}
        crashed = False;
        str = ""
        for car in train:
            str += car[0] + car[1]
        last_s = ''
        for s in str:
            if s in found and s != last_s:
                crashed = True
                break
            last_s = s
            found[s]=1
        if not crashed:
            cnt += 1
    return cnt


    # check if there is a least one solution
def run_tests(input):
    test_cases = int(input.readline())
    for test_no in range(1,test_cases+1):
        n =  int(input.readline())
        cars = input.readline().split()
        assert( n==len(cars) )
        print("Case #{}: {}".format(test_no, solve(cars)))


if __name__ == "__main__":
  try:
      input = open(sys.argv[1],"r")
  except (IOError, IndexError):
      input = sys.stdin
  run_tests(input)
