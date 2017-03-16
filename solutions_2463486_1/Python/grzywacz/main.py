#!/usr/bin/env python

import math
import sys
import bisect

input_file = open(sys.argv[1])
no_cases = int(input_file.next())

def is_palindrome(i):
    s = str(i)
    for x in xrange(max(1, len(s) / 2)):
        if s[x] != s[-(x + 1)]:
            return False
    return True

assert is_palindrome(121)
assert is_palindrome(9)
assert is_palindrome(22322)
assert not is_palindrome(1234)
assert not is_palindrome(11223452211)

palindromes = []
start = 1
end = int(math.floor(math.sqrt(10**14)))
for n in xrange(start, end + 1):
    if is_palindrome(n):
        palindromes.append(n)

for case_no in xrange(no_cases):
    cnt = 0
    A, B = [int(i) for i in input_file.next().strip().split(' ')]
    start = int(math.ceil(math.sqrt(A)))
    end = int(math.floor(math.sqrt(B)))
    i = bisect.bisect_left(palindromes, start)
    j = bisect.bisect_right(palindromes, end)
    for palindrome in palindromes[i:j]:
        if palindrome < start: continue
        if palindrome > end: break
        if is_palindrome(palindrome**2):
            cnt += 1

    print "Case #%d: %d" % (case_no + 1, cnt)
