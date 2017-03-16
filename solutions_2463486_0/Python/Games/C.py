################################################################
def palindrome(x):
    s = str(x)
    n = len(s)
    for i in range(n/2):
        if s[i] != s[n-i-1]:
            return False
    return True

def fair_squares_to(n):
    return [i*i for i in xrange(n) if palindrome(i*i) and palindrome(i)]

FAIRSQUARES = fair_squares_to(10**3)

print FAIRSQUARES
def solve():
    low,high = [int(x) for x in input.readline().split(' ')]
    return len([i for i in FAIRSQUARES if low <= i <= high])

################################################################

from datetime import datetime
time_start = datetime.today()
def now(): return datetime.today() - time_start 

import sys
infilename = sys.argv[1]
outfilename = infilename.replace('.in','.out')

input = open(sys.argv[1], 'r')
output = open(sys.argv[1].replace('.in','.out'), 'w')
n = int(input.readline())

for i in range(1,n+1):
    result = solve()
    print "Case #%d: %s \t %s" % (i, result, now())
    output.write("Case #%d: %s\n" % (i, result))
    output.flush()
