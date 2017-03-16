#!/usr/bin/env python
# -*- coding: utf-8 -*-
#sabu
if __name__ == "__main__":
    testcases = int(input())                    #get number of tests     
    for caseNr in range(1, testcases+1):        #for each testcase
        N = int(input())
        solds = []
        for i in range(2*N-1):
            solds.extend([int(x) for x in input().strip().split()])
        line = []
        for x in sorted(list(set(solds))):
            if solds.count(x)%2 ==1:
                line.append(x)
        print("Case #%i:" % caseNr, ' '.join(map(str, line)))
                    
        