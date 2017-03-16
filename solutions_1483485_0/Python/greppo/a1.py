#!/usr/bin/python
"Speaking in Tongues"
import sys
dbg = 'debug' in sys.argv

"""
ejp mysljylc kd kxveddknmc re jsicpdrysi
our language is impossible to understand

rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
there are twenty six factorial possibilities

de kr kd eoya kw aej tysr re ujdr lkgc jv
so it is okay if you want to just give up
"""

trans = {
        'a': 'y',
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
        'z': 'q',
        ' ': ' ',
}

if dbg:
    print ''.join(sorted(trans.keys()))
    print ''.join(sorted(trans.values()))
    alpha=' abcdefghijklmnopqrstuvwxyz'
    assert ''.join(sorted(trans.keys())) == alpha
    assert ''.join(sorted(trans.values())) == alpha

f = open(sys.argv[1])
T = int(f.readline())
for X in range(1, T+1):
    G = f.readline().strip()
    S = ''.join(trans[a] for a in G)
    print "Case #{}: {}".format(X, S)

