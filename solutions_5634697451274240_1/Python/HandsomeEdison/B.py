#!/usr/bin/env python

def solve(p):
    if not p:
        return 0
    if p[-1] == '+':
        return solve(p[:-1])
    else:
        new_p = map(lambda x: '-' if x == '+' else '+', p[:-1])
        return 1 + solve(new_p)

if __name__ == "__main__":
    T = input()
    for i in xrange(T):
        P = raw_input()
        print 'Case #{}: {}'.format(i + 1, solve(P))
