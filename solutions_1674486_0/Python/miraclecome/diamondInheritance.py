#!/usr/bin/env python2.7
# -*- coding: utf-8 -*-

# Author: Yuande <miraclecome (at) gmail.com>

import sys
import itertools

class RedirectStdoutTo(object):
    def __init__(self, out_new):
        self.out_new = out_new

    def __enter__(self):
        self.out_old = sys.stdout
        sys.stdout = self.out_new

    def __exit__(self, *args):
        sys.stdout = self.out_old

class RedirectStdinTo(object):
    def __init__(self, in_new):
        self.in_new = in_new 

    def __enter__(self):
        self.in_old = sys.stdin
        sys.stdin = self.in_new

    def __exit__(self, *args):
        sys.stdin = self.in_old


def control(inf, outf='b.txt'):
    with open(inf, mode='r') as fdin, open(outf, mode='w') as fdout:
        with RedirectStdinTo(fdin), RedirectStdoutTo(fdout):
            for tc in xrange(1, int(sys.stdin.readline())+1):
                classes = {}
                for mi in xrange(1, int(sys.stdin.readline())+1):
                    m = [int(w) for w in sys.stdin.readline().rstrip('\n').split()]
                    classes[mi] = m[1:]
                bottomlist = []
                for idx, val in classes.items():
                    if len(val) >= 2:
                        bottomlist.append(idx)
                if not bottomlist:
                    print 'Case #%d: No' % (tc, )
                    continue

                yes_flag = 0
                for base in bottomlist:
                    if yes_flag: break
                    check = []
                    iterlist = classes[base]

                    while iterlist:
                        idx = iterlist.pop()
                        if idx in check:
                            yes_flag = 1
                            break
                        check.append(idx)
                        iterlist.extend(classes[idx])
                if yes_flag:
                    print 'Case #%d: Yes' % (tc, )
                else:
                    print 'Case #%d: No' % (tc, )

if __name__ == '__main__':
    control(sys.argv[1])
