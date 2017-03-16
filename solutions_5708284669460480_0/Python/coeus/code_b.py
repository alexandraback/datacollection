from math import floor
from sys import argv
from functools import reduce
import operator

def occurrences(string, sub):
    count = start = 0
    while True:
        start = string.find(sub, start) + 1
        if start > 0:
            count+=1
        else:
            return count

def getBestSubstring(string):
    sub = ''
    for i in range(1, len(string) - 1):
        if string.endswith(string[:i]):
            sub = string[i:]
    return sub

lns = open(argv[1]).readlines()
n_cases = int(lns[0].strip())
for case in range(n_cases):
    k, l, s = lns[3 * case + 1].strip().split()
    k = int(k)
    l = int(l)
    s = int(s)
    K = lns[3 * case + 2].strip()
    L = lns[3 * case + 3].strip()
    expect_single_banana = reduce(operator.mul, [float(K.count(key))/float(len(K)) for key in L], 1)
    if expect_single_banana == 0:
        max_banana = 0.0
        print 'Case #%d: %.7f' % (case+1, 0)
    else:
        best_substring = getBestSubstring(L) if len(L) > 2 else L
        best_string = (L + best_substring * s)[:s]
#        print best_substring
 #       print best_string
        max_banana = occurrences(best_string, L)
        leftover = max_banana - (max_banana * expect_single_banana)
  #      print max_banana, expect_single_banana
        print 'Case #%d: %.7f' % (case+1, leftover)

