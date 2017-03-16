#!/usr/bin/env python3

def read_int():
    return int(input())

from collections import defaultdict

def strToMap(s):
    result = defaultdict(lambda: 0)
    for c in s:
        result[c] += 1;
    return result;

def subtractWord(c,word,m):
    result = m[c]

    for c1 in word:
        if m[c1] < result:
            raise "Underflow"
        m[c1] -= result;

    return result;

def solve(s):
    freq = [0]*10
    m = strToMap(s)

    freq[0] += subtractWord('Z','ZERO',m)
    freq[8] += subtractWord('G','EIGHT',m)
    freq[2] += subtractWord('W','TWO',m)
    freq[6] += subtractWord('X','SIX',m)
    freq[4] += subtractWord('U','FOUR',m)
    freq[5] += subtractWord('F','FIVE',m)
    freq[7] += subtractWord('S','SEVEN',m)
    freq[3] += subtractWord('H','THREE',m)
    freq[1] += subtractWord('O','ONE',m)
    freq[9] += subtractWord('I','NINE',m)

    result = []
    for i in range(10):
        result.extend([str(i)]*freq[i])
        
    return ''.join(result)

for C in range(read_int()):
    I = input().strip()
    R = solve(I)
    print("Case #{}: {}".format(C + 1, R))
