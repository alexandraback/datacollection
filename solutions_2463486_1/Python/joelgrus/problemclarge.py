infile = "C-large-1.in"
outfile = "C-large-1.out"
lines = [l.strip() for l in open(infile,"r")]

outf = open(outfile,"w")#

from collections import defaultdict
from math import sqrt

T = int(lines[0])
lines = lines[1:]

def string_is_palindrome(s):
    n = len(s)
    for i in range(n/2):
        if s[i] != s[n-i-1]:
            return False
    return True

def is_palindrome(n):
    return string_is_palindrome(str(n))

def n_digit_palindromes(n):
    # even and odd separately
    if n == 1:
        for i in range(10):
            yield i
    elif n % 2 == 0:
        for i in range(10 ** (n / 2)):
            yield int(str(i) + str(i)[::-1])
    else:
        for i in range(10 ** (n / 2)):
            for j in range(10):
                yield int(str(i) + str(j) + str(i)[::-1])
                
    
good_palindromes = { i
                     for n in range(8)
                     for i in n_digit_palindromes(n)
                     if is_palindrome(i * i) }

for loop in range(T):
    x,y = [int(c) for c in lines[loop].split()]

    result = len([p for p in good_palindromes
                  if p * p >= x and p * p <= y])

    result = str(result)    
        
    outstr = "Case #" + str(loop+1) + ": " + result
    print outstr
    outf.write(outstr + "\n")

outf.close()
