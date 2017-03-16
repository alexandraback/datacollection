import string
import math
from itertools import chain, combinations

testcase = open('testcase', 'r')
num_cases = int(string.strip(testcase.readline()))


def powerset(iterable):
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

def do_calc(i):
    params = map(int, string.split(string.strip(testcase.readline())))
    c = params[0]
    d = params[1]
    v = params[2]
    vals = map(int, string.split(string.strip(testcase.readline())))
    triangles = 0
    biggest_tri = 0
    new_coins = 0
    for foo in xrange(1, v+1):
        triangles += 1
        biggest_tri += foo
        if biggest_tri >= v:
                break
    for n in xrange(1, triangles+1):
        if n not in vals:
            new_coins += 1
    
    print "Case #"+str(i)+": "+str(new_coins)

for i in xrange(1, num_cases+1):
    do_calc(i)
