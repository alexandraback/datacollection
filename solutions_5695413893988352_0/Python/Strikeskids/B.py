#!/usr/bin/env python3

def brute_scores(c, j):
    l = len(c)

    def tostr(n):
        return ('%%0%dd' % l) % n

    def match(i, b):
        for x, y in zip(tostr(i), b):
            if x != y and y != '?': return False
        return True

    best = None

    for cb in range(10**l):
        if not match(cb, c): continue
        for jb in range(10**l):
            if not match(jb, j): continue
            val = abs(cb - jb)
            if not best or best[0] > val:
                best = (val, [cb, jb])

    return ' '.join(map(tostr, best[1]))


def compute_scores(corig, jorig):
    c = corig.split('')
    j = jorig.split('')
    l = len(c)
    dif = 0

    for i in range(l):
        dif *= 10

def run_test(i):
    print('Case #%d: %s' % (i, brute_scores(*(input().split()))))
    # print('Case #%d: %s' % (i, compute_scores(*(input().split()))))

def main():
    T = int(input())

    for t in range(T):
        run_test(t+1)

def extensive():
    import random
    for i in range(100000):
        compute_insomnia(random.randint(0, 10**6))
    exit(0)

if __name__ == '__main__': main()