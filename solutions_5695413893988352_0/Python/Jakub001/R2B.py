from DomainModel.TestCase import TestCase
import collections
import random
from fractions import Fraction

def opt(s):
    l=[]
    for i,c in enumerate(s):
        if c=='?':
            l.append(i)

    lst = [s]
    for x in l:
        nlst = []
        for y in lst:
            for i in range(10):
                ny = y[:x]+str(i)+y[x+1:]
                nlst.append(ny)
        lst = nlst

    return [int(x) for x in lst]

class R2B:
    def Solve(self):
        tests = int(input())
        for test in range(tests):
            c,j=input().split()
            pc = opt(c)
            pj = opt(j)
            md = 10**6
            sol = None
            for x in pc:
                for y in pj:
                    diff = abs(x-y)
                    if diff<md:
                        md = diff
                        sol = (x,y)

            print("Case #{}: {} {}".format(test + 1, str(sol[0]).zfill(len(c)), str(sol[1]).zfill(len(j))))


    def Tests(self):
        yield TestCase("""4
1? 2?
?2? ??3
? ?
?5 ?0
""", """Case #1: 19 20
Case #2: 023 023
Case #3: 0 0
Case #4: 05 00
""")
