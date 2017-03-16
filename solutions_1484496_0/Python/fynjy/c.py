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
        nums = nums[1:];
        if (len(nums) != N):
            raise Exception("error!");

        sums = dict();

        setDef = None;
        found = False;
        for i in xrange(1, 2**N):
            setDef = [];
            k = i;
            for j in range(21):
                if k & 1:
                    setDef.append(nums[j]);
                k /= 2;
            #print i, setDef;
            curSum = sum(setDef);

            if curSum in sums:
                found = True
                break;

            sums[curSum] = setDef;

        print "Case #%d:" % t;
        if found:
            sd1 = sums[sum(setDef)]; 
            print ' '.join(str(x) for x in sd1);
            print ' '.join(str(x) for x in setDef);
        else:
            print "Impossible";
    

main();
