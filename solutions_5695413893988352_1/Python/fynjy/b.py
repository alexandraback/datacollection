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

def tryit(s1, s2, makeLess, index):
    score1 = []
    score2 = []

    isLess = False;
    isMore = False;

    for i in range(len(s1)):
        c1 = s1[i];
        c2 = s2[i];

        if c1 != '?' and c2 != '?':
            if not isLess and not isMore:
                isLess = c1 < c2;
                isMore = c1 > c2;
        elif c1 != '?' and c2 == '?':
            if isLess:
                c2 = '0'
            elif isMore:
                c2 = '9'
            else:
                if makeLess == -1 and int(c1) > 0 and index == i:
                    c2 = str(int(c1) - 1)
                    isMore = True
                elif makeLess == 1 and int(c1) < 9 and index == i:
                    c2 = str(int(c1) + 1)
                    isLess = True
                else:
                    c2 = c1
        elif c1 == '?' and c2 != '?':
            if isLess:
                c1 = '9'
            elif isMore:
                c1 = '0'
            else:
                if makeLess == -1 and int(c2) > 0 and index == i:
                    c1 = str(int(c2) - 1)
                    isLess = True
                elif makeLess == 1 and int(c2) < 9 and index == i:
                    c1 = str(int(c2) + 1)
                    isMore = True
                else:
                    c1 = c2
        else:
            if isLess:
                c1 = '9';
                c2 = '0';
            elif isMore:
                c1 = '0';
                c2 = '9';
            else:
                if makeLess == -1 and index == i:
                    isLess = True
                    c1 = '0'
                    c2 = '1'
                elif makeLess == 1 and index == i:
                    isMore = True
                    c1 = '1'
                    c2 = '0'
                else:
                    c1 = '0';
                    c2 = '0';

        score1.append(c1)
        score2.append(c2)
        #print "after ", i, score1, score2

    # print "return ", score1, score2
    return (''.join(score1), ''.join(score2))

def main():
    nt = readi();
    for t in range(1, nt+1):
        (s1, s2) = reads().split();

        scores = [];
        for index in range(20):
            for makeLess in range(-1, 2):
                    scores.append(tryit(s1, s2, makeLess, index))
        scoresAndDiff = [(abs(long(s[0]) - long(s[1])), s[0], s[1]) for s in scores]

        # print scoresAndDiff

        list.sort(scoresAndDiff)
        # print scoresAndDiff

        print "Case #%d: %s %s" % (t, ''.join(scoresAndDiff[0][1]), ''.join(scoresAndDiff[0][2]));

        # (score11, score21) = tryit(s1, s2, True);
        # #print "!!!", score11, score21
        # (score12, score22) = tryit(s1, s2, False);
        # #print "!!!", score12, score22

        # abs1 = abs(long(score11) - long(score21))
        # abs2 = abs(long(score12) - long(score22))

        # #print score11, score21, score12, score22
        # #print abs1, abs2

        # if abs1 < abs2:
        #     final1 = score11
        #     final2 = score21
        # elif abs1 > abs2:
        #     final1 = score12
        #     final2 = score22
        # elif score11 < score12:
        #     final1 = score11
        #     final2 = score21
        # else:
        #     final1 = score12
        #     final2 = score22


        # print "Case #%d: %s %s" % (t, ''.join(final1), ''.join(final2));
    

main();
