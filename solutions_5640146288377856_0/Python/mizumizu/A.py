import sys
import collections
import math

def rl():
    return tuple(map(int, raw_input().strip().split()))

def solve(R,C,W):
    #print '====== ' + str(locals())
    if C == 1: return 1
    if C == 2: return 2
    if C == 3: return 3
    if C == 4:
        if W == 2: return 3
        else: return 4
    if C == 5:
        if W == 2 or W == 3: return 4
        else: return 5
    if C == 6:
        if W == 2 or W == 3: return 4
        elif W == 4: return 5
        else: return 6
    if C == 7:
        if W == 2 or W == 3 or W == 4: return 5
        elif W == 5: return 6
        else: return 7
    if C == 8:
        if W == 2 or W == 3 or W == 4: return 5
        elif W == 5: return 6
        elif W == 6: return 7
        else: return 8
    if C == 9:
        if W == 3: return 5
        elif W == 2 or W == 4 or W == 5: return 6
        elif W == 6: return 7
        elif W == 7: return 8
        else: return 9
    if C == 10:
        if W == 2 or W == 3 or W == 4 or W == 5: return 6
        elif W == 6: return 7
        elif W == 7: return 8
        elif W == 8: return 9
        else: return 10
    return 1

'''
xxoxxoxxxx
      ---
 
'''

if __name__ == '__main__':
    for case in range(int(raw_input())):
        print 'Case #%d: %d' % (case+1, solve(*rl()))