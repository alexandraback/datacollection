#!/usr/bin/env python
import sys

if len(sys.argv) == 1:
    sys.stdin = open(__file__.replace('.py', '.in'))
else:
    sys.stdin = open(sys.argv[1])
    sys.stdout = open(sys.argv[1].replace('.in', '') + '.out', 'w')

def get_ints():
    return map(int, raw_input().split())

n_cases = input()

sys.setrecursionlimit(20)

def prev_jump(n):
    if n <= 10:
        return 1
    n_s = str(n)
    n_l = len(n_s)
    prev = int(n_s[:(n_l+1)/2] + '0' * (n_l - 1 - (n_l+1)/2) + '1')
    if str(prev) == str(prev)[::-1]:
        # palindromes aren't valid jump points
        assert n_s[0] == '1'
        return prev_jump(10 ** (n_l - 1) - 1)
    elif prev > n:
        return prev_jump(n - 1)

    return prev

def compute_cost(goal, cost=0):
    cost = 0
    while goal >= 21:
        prev = prev_jump(goal)
        cost += (goal - prev) + 1
        goal = int(str(prev)[::-1])
    cost += goal
    return cost

assert prev_jump(10) == 1

def test_jumps():
    upper = 10**7
    n = upper
    jumps = set()

    costs = [(n, n - 1) for n in range(upper)]

    for n, (cost, prev) in enumerate(costs):
        if n == upper - 1:
            break
        rev = int(str(n)[::-1])
        costs[n + 1] = min(costs[n + 1], (cost + 1, n))
        costs[rev] = min(costs[rev], (cost + 1, n))

    import random
    for x in xrange(10000):
        x = random.randrange(2, upper)
        ca = compute_cost(x)
        cb = costs[x][0]
        assert ca == cb, (x, ca, cb)

    print 'passed'

    while n > 1:
        n = prev_jump(n)
        jumps.add(n)
        n -= 1

    for n, (cost, prev) in enumerate(costs):
        if prev != n - 1:
            assert n in jumps
            jumps.remove(n)

    print jumps

    for x in xrange(1000):
        x = random.randrange(2, 10**14)
        print x, compute_cost(x)

# test_jumps()

for case in xrange(1, n_cases + 1):
    goal, = get_ints()

    print "Case #%d: %s" % (case, compute_cost(goal))
