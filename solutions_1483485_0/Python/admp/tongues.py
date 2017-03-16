#!/usr/bin/env python

import sys
import string

def unmap(encoded, decoded):
    map = dict()
    for e, d in zip(encoded, decoded):
        if not e.isspace():
            map[e] = d
    return map

cypher = {}
cypher.update(unmap('ejp mysljylc kd kxveddknmc re jsicpdrysi', 'our language is impossible to understand'))
cypher.update(unmap('rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd', 'there are twenty six factorial possibilities'))
cypher.update(unmap('de kr kd eoya kw aej tysr re ujdr lkgc jv', 'so it is okay if you want to just give up'))
cypher.update(unmap('qz', 'zq'))
# this comes from small input
trans = string.maketrans(string.lowercase, ''.join([cypher.get(c, c) for c in string.lowercase]))

# print len(cypher) # => 24
# print set(string.lowercase) - set(cypher.keys())

def main():
    lines = sys.stdin.read().splitlines()[1:]
    for index, line in enumerate(lines, start=1):
        print 'Case #%d: %s' % (index, line.translate(trans))

if __name__ == '__main__':
    main()
