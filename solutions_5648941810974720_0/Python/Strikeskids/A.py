#!/usr/bin/env python3
from collections import Counter

def compute_number(s):
    counts = Counter(s)
    counts[0] = counts['Z']
    counts[2] = counts['W']
    counts[4] = counts['U']
    counts[8] = counts['G']
    counts[6] = counts['X']
    counts[7] = counts['S'] - counts[6]
    counts[5] = counts['V'] - counts[7]
    counts[3] = counts['H'] - counts[8]
    counts[1] = counts['O'] - counts[2] - counts[0] - counts[4]
    counts[9] = counts['I'] - counts[8] - counts[6] - counts[5]

    res = []
    for i in range(10):
        res.append(str(i) * counts[i])
    return ''.join(res)

def run_test(i):
    print('Case #%d: %s' % (i, compute_number(input())))

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