#!/usr/bin/env python

def solve(n):
    if n == 0:
        return 'INSOMNIA'
    s = set(str(n))
    current = n
    while len(s) < 10:
        current += n
        s = s.union(set(str(current)))

    return current

if __name__ == "__main__":
    T = input()
    for i in xrange(T):
        N = input()
        print 'Case #{}: {}'.format(i + 1, solve(N))
