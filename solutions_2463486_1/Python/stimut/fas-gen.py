#!/usr/bin/env python

# Generate the list of _root_ fair and square numbers

from math import ceil, floor, sqrt

def is_palindrome(word):
    length = len(word)
    if length == 1:
        return True

    for ii in range(length//2):
        if word[ii] != word[-1-ii]:
            return False

    return True

start = 1
end = floor(sqrt(10**14))

for num in range(start, end+1):
    if not is_palindrome(str(num)):
        continue
    if is_palindrome(str(num*num)):
        print(num)

