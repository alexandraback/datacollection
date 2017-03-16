#!/usr/bin/env python2

import math

T = int(raw_input())

def getnum(word, num):
    result = ''
    for char in word:
        if char == '?': ## use num
            num, tmp = divmod(num, 10)
            result += "%d" % tmp

        elif char == ' ':
            result += ' ' 

        else:
            result += char

    return result

def getscore(code, jam):
    diff = int(code) - int(jam)
    return diff

for case in xrange(1, T+1):
    word = raw_input()
#    print "Case %d << %s" % (case, word)
    marks =  (word).count('?')
    
    best = ''
    bestscore = -10000000000000000000000000
    for num in xrange(10**marks):
        res = getnum(word, num)
        code, jam = map(int,res.split(' '))
        score = getscore(code, jam)
        if abs(score) < abs(bestscore):
            best = res
            bestscore = score
        if abs(score) == abs(bestscore):
            bestcode, bestjam = map(int,best.split(' '))
            if (code) < (bestcode): 
                best = res
                bestscore = score
            if (code) == bestcode and jam < bestjam:
                best = res
                bestscore = score
      
    print "Case #%d: %s" % (case, best)
