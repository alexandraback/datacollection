#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
import math
from decimal import *

if __name__ == "__main__":

    fin = open("C-small1-0.in", "r")
    fout = open("C-small1-0.out", "w")
    T = int(fin.readline())
    #T = int(sys.stdin.readline())
    for k in xrange(0, T):
        fout.write("Case #%i:\n" % (k+1))
        R, N, M, K = map(int, fin.readline().split(' '))
        for i in xrange(0, R):
            P = map(int, fin.readline().split(' '))
            L = {2:0, 3:0, 4:0, 5:0}
            for j in xrange(0, K):
                temp = P[j]
                while temp>1:
                    if temp%125 == 0:
                        L[5] = 3
                        temp /= 125
                    elif temp% 64 ==0:
                        L[4] = 3
                        temp /= 64
                    elif temp% 27 ==0:
                        L[3] = 3
                        temp /= 27
                    elif temp%25 == 0:
                        if L[5] <2:
                            L[5] = 2
                        temp /=25
                    elif temp%16 == 0:
                        if L[2] <2:
                            L[2] = 2
                        if L[4] <1:
                            L[4] = 1
                        temp /=16
                    elif temp%9 == 0:
                        if L[3] <2:
                            L[3] = 2
                        temp /=9
                    elif temp%5 == 0:
                        if L[5] <1:
                            L[5] =1
                        temp/=5
                    elif temp%3 == 0:
                        if L[3] <1:
                            L[3] =1
                        temp/=3
                    elif temp%4 == 0:
                        if L[2] <2:
                            L[2] =2
                        temp/=4
                    elif temp%2 == 0:
                        if L[2] <1:
                            L[2] = 1
                        temp/=2
                if sum(L.values()) >= 3:
                    break
            if sum(L.values()) < 3:
                L[2] += 3-sum(L.values())
            if sum(L.values()) > 3:
                L[2] -=2
                L[4] +=1
            for key in L.keys():
                for i in xrange(0, L[key]):
                    fout.write("%i" % (key))
            fout.write('\n')
    fin.close()
    fout.close()

