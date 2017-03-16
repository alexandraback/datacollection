import sys

cases = sys.stdin.readlines()

# The translation map deduced from the examples (both from the sample
# input and problem description) and the fact that letter q is absent
# in encoded strings while z is absent in decoded strings.
map = {'a': 'y',
       'b': 'h',
       'c': 'e',
       'd': 's',
       'e': 'o',
       'f': 'c',
       'g': 'v',
       'h': 'x',
       'i': 'd',
       'j': 'u',
       'k': 'i',
       'l': 'g',
       'm': 'l',
       'n': 'b',
       'o': 'k',
       'p': 'r',
       'q': 'z',
       'r': 't',
       's': 'n',
       't': 'w',
       'u': 'j',
       'v': 'p',
       'w': 'f',
       'x': 'm',
       'y': 'a',
       'z': 'q'}

# Simply ignore the number of cases that is given and operate on wach
# line instead. A little bit dirty, I admit.
for t in range(1, len(cases)):
    print('Case #', t, sep='', end=': ')
    for c in cases[t]:
        if 'a' <= c and c <= 'z':
            print(map[c], end='')
        else:
            print(c, end='')
