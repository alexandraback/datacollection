# -*- coding: utf-8 -*-
"""
Created on Fri Apr 11 19:32:41 2014

@author: Yun-Jhong Wu
"""

with open('B-small-attempt0.in', 'r') as dat, open('output.txt', '+w') as output:
    n = int(dat.readline())
    for i in range(n):
        t = 0
        c0, f0, x0 = list(map(float, dat.readline().strip('\n').split()))
        c = 0 #farm
        while(x0 > 0):
            g = c*f0 + 2
            if x0/g > c0/g + x0/(g + f0):
                c += 1
                t += c0/g 
            else:
                t += x0/g
                break
        print(t, c, g)            
        output.write('Case #' + str(i + 1) + ': ' + str(t) + '\n')