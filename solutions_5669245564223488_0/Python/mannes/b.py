import math
import string
import copy
import itertools

modulus = 100000007

def modfac(n):
    out = 1
    for i in xrange(1, n+1):
        out *= i
        out = out % modulus
    return out

lower = string.ascii_lowercase

def numtransitions(chars):
    c = 0
    for i in xrange(len(chars)-1):
        if chars[i] != chars[i+1]:
            c += 1
    return c
        

def checktrain(train):
    c = list(copy.deepcopy(train))
    c.sort()
    if numtransitions(train) != numtransitions(c):
        return None
    else:
        out = {}
        for i in xrange(len(train)):
            if train[i] != train[0] and train[i] != train[-1]:
                out[train[i]] = True
        return out

def solve(trains):
    middles = {}
    for train in trains:
        s = checktrain(train)
        if s == None:
            return 0
        else:
            for c in s:
                if c in middles:
                    return 0
                else:
                    middles[c] = True
    for train in trains:
        if train[0] in middles or train[-1] in middles:
            return 0
    ##everything only starts with a, only ends with a, or is all as
    starts = {}
    ends = {}
    both = {}
    for train in trains:
        if train[0] == train[-1]:
            if train[0] in both:
                both[train[0]] += 1
            else:
                both[train[0]] = 1
        else:
            if train[0] in starts:
                return 0
            else:
                starts[train[0]] = train
            if train[-1] in ends:
                return 0
            else:
                ends[train[-1]] = train
    print starts, ends, both
    #check for cycles
    pairs = {}
    for c in starts:
        train = starts[c]
        end = train[-1]
        while end in starts:
            if starts[end] == train:
                return 0
            else:
                end = starts[end][-1]
    # count em'up
    free = 0
    total = 1
    for c in string.ascii_lowercase:
        if c in starts and c in ends:
            if c in both:
                total *= modfac(both[c])
        elif c not in starts and c not in ends:
            if c in both:
                free += 1
                total *= modfac(both[c])
        elif c in starts and c not in ends:
            #this is where things might be sketchy
            free += 1
            if c in both:
                total *= modfac(both[c])
        elif c not in starts and c in ends:
            if c in both:
                total *= modfac(both[c])
    total *= modfac(free)
    return total % modulus

def checkperm(p):
    chars = {p[0][0]: True}
    for t in xrange(len(p)):
        for i in xrange(len(p[t])):
            if t > 0 and i == 0 and p[t][0] != p[t-1][-1]:
                if p[t][0] in chars:
                    return False
                chars[p[t][0]] = True
            elif i > 0 and p[t][i] != p[t][i-1]:
                if p[t][i] in chars:
                    return False
                chars[p[t][i]] = True
    return True
            

def bruteforce(trains):
    c = 0
    for p in itertools.permutations(trains):
        if checkperm(p):
            c += 1
    return c


f = file('b.in', 'r')
lines = f.readlines()
t = int(lines[0])
f.close()

g = file('b.out', 'w')

for i in xrange(1,t+1):
    s = solve(lines[2*i].strip().split())
    g.write("Case #{}: {}\n".format(i, s))
    print "{}: {}".format(i, s)
g.close()
