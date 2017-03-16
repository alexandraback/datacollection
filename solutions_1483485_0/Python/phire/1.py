#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys

d = {' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z': 'q', 'q': 'z'}

def main():
    n = int(sys.stdin.readline())
    for i in xrange(1, n+1):
        _input = sys.stdin.readline().strip()
        _output = "".join(d[x] for x in _input)
        print "Case #" + str(i) + ": " + _output

if __name__ == '__main__':
    main()
