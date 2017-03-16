#!/usr/bin/python3

from sys import argv

infile = open(argv[1])
cases = int(infile.readline())
for i in range(cases):
    a, b = map(int, infile.readline().split())
    p = list(map(float, infile.readline().split()))
    #print('{} {} {}'.format(a, b, p))
    pcorrect = 1
    minimum = 1000000
    for j in range(0, a+1):
        # pcorrect is probability that password was correct up to j
        # compute expected keystrokes for a-j backspaces
        keystrokes = (pcorrect * (a-j + b-j + 1) +
                      (1 - pcorrect) * (a-j + b-j + 1 + b + 1))
        if keystrokes < minimum:
            minimum = keystrokes
        if j < a: pcorrect *= p[j]
    # compute expected keystrokes for enter
    keystrokes = 1 + b + 1
    if keystrokes < minimum:
        minimum = keystrokes
    print('Case #{}: {}'.format(i+1, minimum))
