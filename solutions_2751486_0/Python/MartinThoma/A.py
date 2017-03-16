#!/usr/bin/env python
# -*- coding: utf-8 -*-

def hasAtLestNConsecutiveConsonants(sub, n):
    for start in range(0, len(sub)-n+1):
        count = 0
        for el in sub[start:]:
            if el not in ["a","e", "i","o","u"]:
                count += 1
            else:
                break
        if count >= n:
            return True
    return False

def solve(name, n):
    nVal = 0
    for start in range(0, len(name)-n+1):
        for end in range(start+n, len(name)+1):
            if hasAtLestNConsecutiveConsonants(name[start:end], n):
                nVal += 1
    return nVal
 
if __name__ == "__main__":
    testcases = input()
      
    for caseNr in xrange(1, testcases+1):
        name, n = raw_input().split(" ")
        print("Case #%i: %s" % (caseNr, solve(name, int(n))))
