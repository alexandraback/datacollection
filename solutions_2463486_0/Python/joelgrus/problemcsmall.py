infile = "C-small-attempt0.in"
outfile = "C-small.out"
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

for loop in range(T):
    x,y = [int(c) for c in lines[loop].split()]

    lo = int(sqrt(x))
    hi = int(sqrt(y)) + 1

    result = 0

    for i in range(lo,hi):
        sq = i * i
        if is_palindrome(i) and is_palindrome(sq) and sq >= x and sq <= y:
            print i,i*i
            result += 1

    result = str(result)    
        
    outstr = "Case #" + str(loop+1) + ": " + result
    print outstr
    outf.write(outstr + "\n")

outf.close()
