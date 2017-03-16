#!python

import sys
import itertools
from collections import Counter

def winner(l):
    c = Counter(l)
    letter, n = c.most_common(1)[0]
    if (letter in ('O', 'X')
        and (n == 4 or (n == 3 and 'T' in c))):
        raise StopIteration(letter)

def result(tb):
    try:
        for l in tb:
            winner(l)
        winner([tb[i][i] for i in range(4)])
        winner([tb[i][3-i] for i in range(4)])
        for col in zip(*tb):
            winner(col)
    except StopIteration as e:
        return '{} won'.format(str(e))
    else:
        if '.' in ''.join(tb):
            return "Game has not completed"
        else:
            return "Draw"

if __name__ == '__main__':
    sys.stdin.readline()
    t = 0
    while True:
        t += 1
        l = [sys.stdin.readline().strip() for i in range(4)]
        sys.stdin.readline()
        if not l[0]:
            break

        print("Case #{}: {}".format(str(t), result(l)))
