#! /usr/bin/python
# -*- coding: utf8 -*-

import itertools

def do_calc(line):
    n = line[0]
    j = line[1:]
    j.sort()
    c = {}
    for p in range(len(j)):
        for q in itertools.combinations(j,p+1):
            s = sum(q)
            if c.has_key(s):
#                print list(c[s]),list(q),sum(c[s]),sum(q)
                return list(c[s]),list(q)
            c[s] = q
    return [], []

def main():
    for c in range(input()):
        line = map(int,raw_input().split())
        result = do_calc(line)
        print 'Case #%d:' % ( c+1 )
        if len(result[0]) > 0:
            print ' '.join("%d" % x for x in result[0])
            print ' '.join("%d" % x for x in result[1])
        else:
            print 'Impossible'
if __name__ == '__main__':
    main()
