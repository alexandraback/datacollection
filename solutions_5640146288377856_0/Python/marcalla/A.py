#!/usr/bin/env python3

import sys

if __name__ == "__main__":

    T = int(sys.stdin.readline())
    for t in range (1, T+1):
        R, C, W = map(int, sys.stdin.readline().split())
        nmissPerRow = C // W
        totalmiss = nmissPerRow * R #Although the last one is a hit!
        if C % W != 0: # The trick of moving within the row
            totalmiss += 1
        totalscore = totalmiss + W - 1
        print ("Case #%d: %d" % (t, totalscore))
