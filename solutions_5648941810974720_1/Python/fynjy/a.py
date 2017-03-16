#!/usr/bin/python

import sys;
import os.path; 
from collections import *;
from Queue import *;
import numpy as np;

def readi():
    return int(sys.stdin.readline().strip());

def readia():
    return [int(x) for x in sys.stdin.readline().strip().split()];

def readfa():
    return [float(x) for x in sys.stdin.readline().strip().split()];

def reads():
    return sys.stdin.readline().strip();

digits = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"];


def main():
    nt = readi();
    for t in range(1, nt+1):
        s = reads();

        chars = dict();
        for c in s:
            chars[c] = chars.get(c, 0) + 1;

        # print >> sys.stderr, chars

        numbers = [];

        def check(c, num): 
            while chars.get(c, 0) > 0:
                numbers.append(num)
                for c1 in digits[num]:
                    chars[c1] -= 1;
            # print >> sys.stderr, "check %c %d: chars = %s" % (c, num, str(chars))


        check('Z', 0)
        check('W', 2)
        check('U', 4)
        check('X', 6)
        check('G', 8)
        check('T', 3)
        check('F', 5)
        check('S', 7)
        check('O', 1)
        check('N', 9)

        for c, v in chars.iteritems():
            if v != 0:
                print >>sys.stderr, "Error in test %d: %c -> %d" % (t, c, v)

        list.sort(numbers)
        print "Case #%d: %s" % (t, ''.join(str(n) for n in numbers));
    
        
main();
