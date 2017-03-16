#!/usr/bin/python

import sys;
import os.path; 
THIS_DIR = os.path.dirname(sys.argv[0]);
sys.path.append(THIS_DIR + '/..')
from util import *;
import collections;

def is_multiple_paths(inh, start):
    was = set();
    q = collections.deque();
    q.append(start);

    while len(q) > 0:
        cur = q.pop();
        if cur in was:
            return True;
        was.add(cur);
        for k in inh[cur]:
            q.append(k);
    return False;
            

def main():
    nt = readi();
    for t in range(1, nt+1):
        N = readi();
        inh = [];
        for i in range(N):
            nums = readia();
            m = nums[0];
            nums = nums[1:];
            if m != len(nums):
                raise Exception("error!");

            inh.append([x-1 for x in nums]);

        isMult = False;
        for i  in range(N):
            if is_multiple_paths(inh, i):
                isMult = True;
                break;

        print "Case #%d: %s" % (t, "Yes" if isMult else "No");
    

main();
