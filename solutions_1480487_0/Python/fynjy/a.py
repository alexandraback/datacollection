#!/usr/bin/python

import sys;
import os.path; 
THIS_DIR = os.path.dirname(sys.argv[0]);
sys.path.append(THIS_DIR + '/..')
from util import *;

def main():
    nt = readi();
    for t in range(1, nt+1):
        nums = readia();
        N = nums[0];
        scores = nums[1:];
        if len(scores) != N:
            print >>sys.stderr, "error: ", nums;

        sumScores = sum(scores);
        normScores = [float(x) / sumScores for x in scores];

        l = 0.0;
        r = 1.0;
        while abs(r - l) > 1e-15:
            m = (r + l) / 2.0;
            vs = [max(m + normScores[0] - score, 0) for score in normScores];
            sumVs = sum(vs);
            if sumVs > 1.0:
                r = m;
            else:
                l = m;

        vs = [max(l + normScores[0] - score, 0) for score in normScores];


        print "Case #%d: %s" % (t, ' '.join("%0.6f" % (x*100.0) for x in vs));
    

main();
