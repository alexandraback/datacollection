import sys
import random
from itertools import permutations
import re


def solve():
    string = sys.stdin.readline().replace('\n','')
    print len(re.findall('\++', string)) - len(re.findall('\++$', string)) + len(re.findall('\-+', string))
    

t = int(sys.stdin.readline())
for i in xrange(t):
    print "Case #%d:" % (i+1),
    solve()

