import itertools
from decimal import *
from Common_Functions import *

from math import *
def prob82():
    f = open("C:\Users\Jackie\Documents\Project Euler\Python\prob81.txt")
    lines = f.readlines()
    cases = int(lines.pop(0))
    for i in range(cases):
        l = lines.pop(0).split()
        r = Decimal(l[0])
        t = Decimal(l[1])
        print r, t
        n = (1-2*r + Decimal(str(sqrt((2*r-1)**2 + 8*t))))/4
        print Decimal(str(sqrt((2*r-1)**2 + 8*t))) + 1 - 2*r
        print "Case #%d:" %(i+1),
        print n
        n = str(floor(n))
        print n.rstrip('0').rstrip('.')

from math import *
def main():
    f = open("C:\Users\Jackie\Documents\Project Euler\Python\prob81.txt")
    lines = f.readlines()
    cases = int(lines.pop(0))
    for i in range(cases):
        l = lines.pop(0).split()
        r = int(l[0])
        t = int(l[1])
        #print r, t
        n = (1-2*r + sqrt((2*r-1)**2 + 8*t))/4
        print "Case #%d:" %(i+1),
        n = str(floor(n))
        print n.rstrip('0').rstrip('.')



