from operator import and_
from functools import reduce
from collections import defaultdict
import random
import sys
sys.setrecursionlimit(10000) 

read_ints = lambda: map(int, raw_input().split())
read_int  = input

def go2(arr, prod, dep):
    mm[prod].add(repr(arr))
    if dep == len(arr):
        return
    go2(arr, prod, dep+1)
    go2(arr, prod*arr[dep], dep+1)

def go(start, prod, dep):
    global n, m
    if dep == n:
        go2(arr[:dep], 1, 0)
        return
    for i in xrange(start, m+1):
        arr[dep] = i
        go(i, prod*i, dep+1)

# INIT...
read_int() # T
r, n, m, k = read_ints()
arr = [0] * n
mm = defaultdict(set)
#mm = defaultdict(int)
go(2, 1, 0)
#print len(mm)

print 'Case #1:' # hmm...

for no_t in xrange(r):
    a = read_ints()
    s = reduce(and_, map(lambda x: mm[x], a))
    ans = eval(random.choice(list(s)))
    print '%s' % ''.join(map(str,ans))
