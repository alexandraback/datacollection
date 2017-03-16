#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

t = dict()
t['y'] = 'a'
t['n'] = 'b'
t['f'] = 'c'
t['i'] = 'd'
t['c'] = 'e'
t['w'] = 'f'
t['l'] = 'g'
t['b'] = 'h'
t['k'] = 'i'
t['u'] = 'j'
t['o'] = 'k'
t['m'] = 'l'
t['x'] = 'm'
t['s'] = 'n'
t['e'] = 'o'
t['v'] = 'p'
t['z'] = 'q'
t['p'] = 'r'
t['d'] = 's'
t['r'] = 't'
t['j'] = 'u'
t['g'] = 'v'
t['t'] = 'w'
t['h'] = 'x'
t['a'] = 'y'
t['q'] = 'z'
t[' '] = ' '


def getRet(text):
    ret = dict()
    for i in xrange(1,nbFlavor+1):
        ret[i] = 2
    cus.sort()
    for v in cus:
        if v[0] == 1:
            a = v[1]
            b = v[2]
            if ret[a] != 2 and ret[a] != b:
                return 'IMPOSSIBLE'
            ret[a] = b
        else:
            break
    return getNb2(nbFlavor,ret,cus)

if __name__=="__main__":
    inFile = sys.argv[1]
    inFileObj = file(inFile)
    inLines = [line.strip() for line in inFileObj]
    nbTest = int(inLines[0])
    for i in xrange(nbTest):
        text = inLines[i+1]
        textN = [t[x] for x in text]
        textNew = ''.join(textN)
        s = 'Case #%d: ' % (i+1)
        s += textNew
        print s
