# coding: utf8

lmap = {
    'a': 'y', 'b': 'h', 'c': 'e', 'd': 's', 'e': 'o', 'f': 'c', 'g': 'v',
    'h': 'x', 'i': 'd', 'j': 'u', 'k': 'i', 'l': 'g', 'm': 'l', 'n': 'b',
    'o': 'k', 'p': 'r', 'q': 'z', 'r': 't', 's': 'n', 't': 'w', 'u': 'j',
    'v': 'p', 'w': 'f', 'x': 'm', 'y': 'a', 'z': 'q', ' ': ' ',
}

for case in xrange(1, int(raw_input()) + 1):
    a = [lmap[c] for c in raw_input().strip()]
    print 'Case #%d: %s' % (case, ''.join(a))
