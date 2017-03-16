import sys
import random
from itertools import permutations


def flip(k):
    if k < 10:
        return k
    
    # k = 10a+b
    b = k%10
    a = int(k/10)
    digits = len(str(a))
    return b*(10**digits)+flip(a)

solution = []

for n in xrange(10):
    solution.append(n)

def sol(k):
    if len(solution) <=k:
        best = sol(k-1)
        a = flip(k)
        if a < k and flip(a) == k:
            best = min(best, sol(a))
        solution.append(best+1)
    
    return solution[k]

for n in xrange(10**6):
    sol(n)

def solve():
    n = int(sys.stdin.readline())
    
    print sol(n)
    
t = int(sys.stdin.readline())
for i in xrange(t):
    print "Case #%d:" % (i+1),
    solve()

