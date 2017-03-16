import sys
import copy
import itertools
from collections import defaultdict
import math
import datetime

epsilon = 1e-6

N_MAX = 1e6

memoized = {} # n -> steps needed to reach n
def memoize():
    global memoized
    memoized[1] = 1
    recent = [1]
    while len(memoized) < N_MAX:
        curr = recent.pop(0)
        m = memoized[curr]
        # log(str(curr)+' '+str(m))
        if curr+1 <= N_MAX and curr+1 not in memoized:
            # log('    '+str(curr+1))
            memoized[curr+1] = m+1
            recent.append(curr+1)
        reversed = int(str(curr)[-1::-1])
        if reversed < N_MAX and reversed not in memoized:
            # log('   '+str(reversed))
            memoized[reversed] = m+1
            recent.append(reversed)

def log(msg):
    print(msg, file=sys.stderr)

def solve(n):
    global memoized
    return memoized[n]

def testcase():
    n = int(sys.stdin.readline().strip())
    solution = solve(n)
    testcase.id += 1
    print('Case #{}: {}'.format(testcase.id, solution))
testcase.id = 0

memoize()

start = datetime.datetime.now()
t = int(sys.stdin.readline())
for i in range(t):
    log('Case #{}'.format(i+1))
    testcase()
log(datetime.datetime.now() - start)

