'''
Created on 14 apr. 2012

@author: Peter
'''
from sys import *

def get_normal_maxpoint(point):
    total = point + point + point - 2
    if total > 0:
        return total
    else:
        return point
#    if point == 0:
#        return 0
#    elif point ==1:
#        return 1
#    elif point==3:
#        return 2
    
#    maxpoint = point / 3
#    if point % 3 > 0:
#        maxpoint += 1
#    return maxpoint

def get_supr_maxpoint(point):
    total = point + point + point - 4
    if total > 0:
        return total
    else:
        return point

def solve(items):
    num_googlers = int(items[0])
    supr_triplets = int(items[1])
    max_point = int(items[2])
    scores = []

    for x in xrange(3, len(items)):
        scores.append(int(items[x]))
    surprise = 0
    maxpoints = 0
    normal_maxpoint = get_normal_maxpoint(max_point)
    supr_maxpoint = get_supr_maxpoint(max_point)    
    for score in scores:
        if score >= normal_maxpoint:
            maxpoints += 1
        elif score >= supr_maxpoint and surprise < supr_triplets:
            maxpoints += 1
            surprise += 1
       # print normal_maxpoint, supr_maxpoint, max_point, maxpoints, surprise
            
    return maxpoints
cases = int(raw_input())
for case in xrange(1, cases + 1):
    items = map(str, stdin.readline().split())
    
    print "Case #%s: %s" % (case, solve(items))
