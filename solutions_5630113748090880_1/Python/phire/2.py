#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys

def main():
    T = int(sys.stdin.readline())
    for t in xrange(1, T+1):
        N = int(sys.stdin.readline())
        d = dict()
        for k in xrange(2*N - 1):
            vals = map(int, sys.stdin.readline().split())
            for v in vals:
                d[v] = d.get(v, 0) + 1
        ret = []
        for k, v in d.iteritems():
            if v & 1:
                ret.append(k)
        assert len(ret) == N
        print "Case #%d: %s" % (t, " ".join(map(str, sorted(ret))))

if __name__ == '__main__':
    main()
