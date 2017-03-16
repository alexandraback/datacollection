#!/usr/bin/python

import sys
import random
import itertools

def pair(a, b):
    pair_set = set()
    ret = 0
    for n in range(a, b+1):
        s = str(n)
        #if n not in pair_set:
        for i in range(1,len(s)):
            s1 = s[i:]
            s1 = s1 + s[:i]
            v = int(s1)
            if v >= a and v <= b and v != n:
                pair_set.add((n, v))
                    
    return len(pair_set)/2

def main(argv):
    if len(argv) != 2:
        print "Usage:", argv[0], "<input file>"
        return

    f = open(argv[1], "r")  
    o = open(argv[1]+".out", "w")  
    cc = int(f.readline())  
    print cc, "cases"  
    for c in range(cc):  
        a = map(int, f.readline().split())
        A = a[0]
        B = a[1]
        ret = pair(A, B)

        o.write("Case #%d: %d\n" % (c+1, ret))
    o.close()  

if __name__ == "__main__":
    main(sys.argv)
