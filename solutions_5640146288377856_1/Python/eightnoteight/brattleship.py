#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin

def main():
    for t in xrange(1, int(raw_input()) + 1):
        r, c, w = map(int, raw_input().split())
        print 'Case #%s: %s' % (t, r*(c // w) + w - 1 + (w + c % w != w))

main()
