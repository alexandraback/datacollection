import sys
from itertools import *
cases = int(raw_input())

def check(s):
    occured = [0 for i in range(26)]
    last = "#"
    for c in s:
        if c != last:
            if occured[ord(c) - ord('a')] == 1:
                return False
            occured[ord(c) - ord('a')] = 1
            last = c
    return True

def rem_repeat(s):
    last = "#"
    res = ""
    for c in s:
        if c != last:
            last = c
            res += c
    return res

for cas in range(cases):
    n = int(raw_input())
    trains = raw_input().split()
    assert(n == len(trains))
    trains = map(rem_repeat, trains)
    good = 0
    for train_ord in permutations(trains):
        att = "".join(train_ord)
        if check(att):
            good = (good + 1)%1000000007
    print ("Case #%d: %d" % (cas+1, good))
