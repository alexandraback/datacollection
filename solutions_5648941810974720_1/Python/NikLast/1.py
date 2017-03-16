#!/usr/bin/env python2

def even(word): #Z W U X G
    result = []
    cursor = 0

    new_word = []

    while cursor<len(word):
        char = word[cursor]
        if char == 'Z':
            found
            
        

T = int(raw_input())

for case in xrange(1, T+1):
    word = raw_input()

    count = {}
    for char in xrange(ord('A'), ord('Z')+1):
        count[chr(char)] = 0

    for char in word:
            count[char] += 1
    
    result = [0]*10
    result[0] = count['Z']
    result[2] = count['W']
    result[4] = count['U']
    result[6] = count['X']
    result[8] = count['G']

    result[1] = count['O'] - (result[2] + result[4] + result[0])
    result[3] = count['T'] - (result[2] + result[8])
    result[5] = count['F'] - result[4]
    result[7] = count['S'] - result[6]
    result[9] = (count['N'] - (result[1] + result[7]))/2 

    number = ""
    for i, digit in enumerate(result):
        number += (("%d" % i)*result[i])

    print "Case #%d: %s" % (case, number)
