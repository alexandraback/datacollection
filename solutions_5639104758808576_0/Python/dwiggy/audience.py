#!/usr/bin/python3
from sys import stdin

cases = int(stdin.readline())

for c in range(1,cases+1):
    line = stdin.readline().strip()
    [levels, people] = line.split(' ', 1)
    standing=0
    friends=0
    for i in range(0, int(levels)+1):
        if (standing >= i):
            standing += int(people[i])
        else:
            friends += i-standing
            standing += i-standing + int(people[i])
    print (('Case #%d: %d' % (c,friends)))
        
