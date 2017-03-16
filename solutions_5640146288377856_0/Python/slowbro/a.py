from __future__ import division
from collections import defaultdict
import math
import sys

#myin = sys.stdin
myin = open(sys.argv[1], 'rb')

def rstr(): return myin.readline().strip()
def rstrs(): return myin.readline().strip().split()
def rnum():  return int(rstr())
def rnums():  return list(int(x) for x in rstrs())
def window(vec, window_size=2):
    for i in xrange(len(vec)-window_size+1):
        yield vec[i:(i+window_size)]

def solve():
    R,C,W = rnums()
    ret = R * (C // W)
    if C % W > 0:
        ret += W
    else:
        ret += (W-1)
    return ret

def main():
    T = rnum()
    for ti in xrange(1,T+1):
        ret = solve()
        print "Case #%i: %s"%(ti, ret%1000000007)
    return

if __name__ == '__main__':
    main()
