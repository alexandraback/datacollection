#!/usr/bin/env python3

# Script to produce the list of fair and square numbers for large input 1.

for i in range(1, 10000000):
    s = str(i)
    if s == ''.join(reversed(s)):
        s = str(i*i)
        if s == ''.join(reversed(s)):
            print(s)
