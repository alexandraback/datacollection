#
# Google Code Jam 2014
# Roaund 1C: A. Part Elf
# submission by EnTerr
#

'''
Input
The first line of the input gives the number of test cases, T. T lines follow. 
Each contains a fraction of the form P/Q, where P and Q are integers.

Output
For each test case, output one line containing "Case #x: y", where x is the test case 
number (starting from 1) and y is the minimum number of generations ago a 1/1 Elf 
in her family could have been if she is P/Q Elf. If it's impossible that Vida could 
be P/Q Elf, y should be the string "impossible" (without the quotes).

Limits
1 <= T <= 100.

Small dataset
1 <= P < Q <= 1000.
P and Q have no common factors. That means P/Q is a fraction in lowest terms.

Large dataset
1 <= P < Q <= 1012.
P and Q may have common factors. P/Q is not guaranteed to be a fraction in lowest terms.

Sample

*Input 
5
1/2
3/4
1/4
2/23
123/31488

*Output 
Case #1: 1
Case #2: 1
Case #3: 2
Case #4: impossible
Case #5: 8

'''

import sys
from time import clock

f = open(sys.argv[1])
def input(): return f.readline().strip();

from fractions import gcd

def partElf(p, q):
    if (2**40) % (q / gcd(p, q)):
        return 'impossible'
    else:
        i = 0
        while p < q:
            i += 1
            p *= 2
        return i

#clk = clock()

for caseNo in xrange(1, int(input())+1):
    # print >>sys.stderr, caseNo
    P, Q = map(int, input().split('/'))
    print 'Case #%d:' % caseNo, partElf(P, Q)
    
#print >>sys.stderr, 'time= %.1f seconds' % (clock()-clk )

