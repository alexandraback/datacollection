#!/usr/bin/python
from itertools import product


def count_substr(text, substr):
    result = 0
    start = -1
    while True:
        start = text.find(substr, start + 1)
        if start < 0:
            return result
        else:
            result+= 1


def solve(keyboard, S, target):
    experiment = [
        count_substr("".join(text), target)
        for text in product(keyboard, repeat=S)
    ]
    #print experiment
    return 1.0 * max(experiment) - 1.0 * sum(experiment) / len(experiment)


if __name__ == '__main__':
    T = int(raw_input())
    for t in range(T):
        K, L, S = map(int, raw_input().split())
        keyboard = raw_input().strip()
        target = raw_input().strip()
        answer = solve(keyboard, S, target)
        print "Case #{0}: {1}".format(t + 1, answer)
