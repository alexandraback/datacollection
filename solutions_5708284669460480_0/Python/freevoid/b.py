from __future__ import division
import itertools

itertools.product


def solve(K, L, S, keyboard, target):


    words = itertools.product(keyboard, repeat=S)
    total = 0
    maxnbananas = 0
    sumnbananas = 0

    for word in words:
        total += 1
        word = ''.join(word)
        nbananas = occurrences(word, target)
        maxnbananas = max(nbananas, maxnbananas)
        sumnbananas += nbananas

    return maxnbananas - (sumnbananas / total)



def occurrences(string, sub):
    count = start = 0
    while True:
        start = string.find(sub, start) + 1
        if start > 0:
            count+=1
        else:
            return count

t = input()
for i in range(t):
    K, L, S = map(int, raw_input().split(' '))
    keyboard = raw_input().strip()
    target = raw_input().strip()

    print 'Case #%d: %.8f' % (i + 1, solve(K, L, S, keyboard, target))
