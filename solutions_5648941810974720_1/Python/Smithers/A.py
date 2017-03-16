#!/usr/bin/env python3

# Google Code Jam Round 1B 2016
# Problem A. Getting the Digits
# Solution in Python
# By Smithers

for x in range(1, int(input()) + 1):
    s = input()
    
    cletters = {}
    for i in range(26):
        cletters[chr(ord('A') + i)] = 0
    for c in s:
        cletters[c] += 1
    
    cdigits = [0] * 10
    
    def doit(n, letter, word):
        cdigits[n] = cletters[letter]
        for l in word:
            cletters[l] -= cdigits[n]
    
    doit(0, 'Z', 'ZERO')
    doit(2, 'W', 'TWO')
    doit(6, 'X', 'SIX')
    doit(8, 'G', 'EIGHT')
    doit(3, 'T', 'THREE')
    doit(4, 'R', 'FOUR')
    doit(1, 'O', 'ONE')
    doit(5, 'F', 'FIVE')
    doit(7, 'V', 'SEVEN')
    doit(9, 'E', 'NINE')
    
    print('Case #' + str(x) + ':', ''.join(str(i) * n for (i, n) in enumerate(cdigits)))
