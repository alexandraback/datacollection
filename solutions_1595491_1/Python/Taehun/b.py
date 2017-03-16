#!/usr/bin/python

import sys

def is_valid(score, s, p):
    ret = False
    max_s = 3*p
    if score > max_s:
        ret = True
    elif max_s == score:
        ret = True
    elif 2*p+(p-1) == score:
        ret = True
    elif p+2*(p-1) == score:
        ret = True
    
    if not ret and s > 0 and p >= 2:
        if 2*p+(p-2) == score:
            ret = True
            s = s-1
        elif p+2*(p-2) == score:
            ret = True
            s = s-1
        elif p+(p-1)+(p-2) == score:
            ret = True
            s = s-1

    return ret, s

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
        n = a[0] # the number of googler
        s = a[1] # the number of surpring score
        p = a[2] # the score of best result
        g = a[3:] # the total score each googler

        count = 0
        for i in g:
            ret, s = is_valid(i, s, p)
            if ret:
                count = count+1

        o.write("Case #%d: %d\n" % (c+1, count))  
    o.close()  

if __name__ == "__main__":
    main(sys.argv)
