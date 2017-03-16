#!/usr/bin/env python

def solve_war(n, k):
    n = list(n)
    k = list(k)
    score = 0
    while n:
        np = n.pop()
        try:
            kp = min(w for w in k if w > np)
        except:
            kp = min(k)
            score += 1
        k.remove(kp)
    return score

def solve_dwar(n, k):
    n = sorted(n)
    k = sorted(k)
    score = 0
    while n:
        while n and n[0] < k[0]:
            # Cannot win this one, forcing K to give up his heaviest block
            n.pop(0)
            k.pop()
        while n and n[0] > k[0]:
            # If he has a lighter block than my lightest, I score a point by
            # announcing weight 0.99999 (and forcing K to pick his lightest)
            n.pop(0)
            k.pop(0)
            score += 1
    return score

T = int(raw_input().strip())
for t in range(T):
    raw_input()  # We don't need to read number of blocks
    n = [float(f) for f in raw_input().strip().split()]
    k = [float(f) for f in raw_input().strip().split()]
    print 'Case #%d: %d %d' % (t+1, solve_dwar(n, k), solve_war(n, k))
