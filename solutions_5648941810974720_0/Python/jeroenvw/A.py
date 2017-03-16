#!/usr/bin/python

from __future__ import division
from gcj import *

# boolean flags, reachable via OPTS.flagname. Space separated in string
FLAGS = ''

numbers = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN",
"EIGHT", "NINE"]

def case():
    c2n = {}
    chars = {}
    for i, n in enumerate(numbers):
        for c in n:
            c2n.setdefault(c, []).append(i)
            chars.setdefault(c, 0)

    word = line()
    for c in word:
        chars[c] += 1

    res = [0] * 10
    repeat = True
    while repeat:
        repeat = False
        #pprint(c2n)
        #pprint(chars)
        for c, n in c2n.items():
            if len(n) == 1:
                n, = n
                numfound = chars[c]
                print "Found %d times %s must be %s" % (numfound, c, n)
                res[n] += numfound
                for char in numbers[n]:
                    chars[char] -= numfound
                    c2n[char].remove(n)
                repeat = True
                break
    return ''.join(str(i) * res[i] for i in range(10))


if __name__ == '__main__':
    main()
