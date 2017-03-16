#!/usr/bin/env python

import sys, os, re
#from collections import deque

#---------------------------------------------------
# variable 
#---------------------------------------------------
vows='aeiou'

#---------------------------------------------------
# Function 
#---------------------------------------------------
def parse_str(s, n):
    list = []
    cnt = 0
    for idx in xrange(len(s)):
        c = s[idx]
        if c not in vows:
            cnt += 1 
        else:
            if cnt >= n:
                list.append([idx-cnt,cnt])
            #print >> sys.stderr, cnt, c, n 
            cnt = 0
    if cnt >= n:
        list.append([len(s)-cnt,cnt])
    return list

def cons(s, n):
    total = len(s)
    list = parse_str(s, n)
    #print >> sys.stderr, list
    limit = -1 
    v = 0
    for idx, cnt in list:
        left, right = idx-limit, total-idx-n+1
        v += (left*right) 
        #print >> sys.stderr, v, left, right
        limit = idx+cnt-n
        if cnt > n:
            det = cnt - n
            v += ((right-1+right-det)*det/2)
    return v

def load_file(filename):
    with open(filename, 'rU') as f:
        number = int(f.readline())
        for i in range(number):
            buff = f.readline().split()
            s = buff[0]
            n = int(buff[1])
            result = cons(s, n)
            print 'Case #%d: %s' % (i+1, result)
    return

#---------------------------------------------------
# Entry Point 
#---------------------------------------------------
def main():
    #if len(sys.argv) < 3:
    #    print 'Usage:'
    #    print '  %s arg1 arg2' % os.path.basename(sys.argv[0])
    #    sys.exit(1)

    load_file (sys.argv[1])

    return

#---------------------------------------------------
# Unit Test Entry 
#---------------------------------------------------
if __name__ == '__main__':
    main()


