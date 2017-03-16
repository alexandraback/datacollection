#!/usr/bin/env python
# -*- coding: utf-8 -*-
#sabu
if __name__ == "__main__":
    testcases = int(input())                    #get number of tests     
    for caseNr in range(1, testcases+1):        #for each testcase
        word = input().strip()
        lastw = word[0]
        for c in list(word[1:]):
            if c>=lastw[0]:
                lastw = str(c) + lastw
            else:
                lastw += c
        print("Case #%i:" % caseNr, lastw)
                    
        