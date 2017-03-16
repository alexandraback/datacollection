from DomainModel.TestCase import TestCase
import collections
import random
from fractions import Fraction


def opt(s):
    l = []
    for i, c in enumerate(s):
        if c == '?':
            l.append(i)

    lst = [s]
    for x in l:
        nlst = []
        for y in lst:
            for i in range(10):
                ny = y[:x] + str(i) + y[x + 1:]
                nlst.append(ny)
        lst = nlst

    return [int(x) for x in lst]


class R2B:
    def Solve(self):
        tests = int(input())
        for test in range(tests):
            c, j = input().split()
            n = max(len(c), len(j))
            c = c.zfill(n)
            j = j.zfill(n)

            smaller = 0
            fc = ''
            fj = ''
            prob = []
            for i in range(n):
                a = c[i]
                b = j[i]
                if a != '?' and b != '?':
                    if smaller == 0:
                        if a < b:
                            smaller = 1
                        elif a > b:
                            smaller = -1
                elif a == '?' and b == '?':
                    if smaller == 0:
                        prob.append((i, 0))
                        a = '0'
                        b = '0'
                    elif smaller == 1:
                        a = '9'
                        b = '0'
                    else:
                        a = '0'
                        b = '9'
                elif a == '?':
                    if smaller == 0:
                        prob.append((i, 1))
                        a = b
                    elif smaller == 1:
                        a = '9'
                    else:
                        a = '0'
                else:
                    if smaller == 0:
                        prob.append((i, 2))
                        b = a
                    elif smaller == 1:
                        b = '0'
                    else:
                        b = '9'
                fc += a
                fj += b
            for i, mode in prob[::-1]:
                a = int(fc[i + 1:]) if fc[i + 1:] else 0
                b = int(fj[i + 1:]) if fj[i + 1:] else 0
                mul = 10 ** (n - i - 1)
                dif = a - b
                if abs(dif) > mul//2:
                    repA = fc[i]
                    repB = fj[i]
                    if dif > 0:
                        if (mode == 0 or mode == 1) and fj[i] != '0':
                            repA = chr(ord(fj[i]) - 1)
                        elif (mode == 2 or mode == 0) and fj[i] != '9':
                            repB = chr(ord(fj[i]) + 1)
                    elif dif < 0:
                        if (mode == 0 or mode == 1) and fc[i] != '9':
                            repA = chr(ord(fc[i]) + 1)
                        elif (mode == 2 or mode == 0) and fc[i] != '0':
                            repB = chr(ord(fc[i]) - 1)
                    fc = fc[:i] + repA + fc[i + 1:]
                    fj = fj[:i] + repB + fj[i + 1:]

            print("Case #{}: {} {}".format(test + 1, fc, fj))

    def SolveX(self):
        tests = int(input())
        for test in range(tests):
            c, j = input().split()
            pc = opt(c)
            pj = opt(j)
            md = 10 ** 6
            sol = None
            for x in pc:
                for y in pj:
                    diff = abs(x - y)
                    if diff < md:
                        md = diff
                        sol = (x, y)

            print("Case #{}: {} {}".format(test + 1, str(sol[0]).zfill(len(c)), str(sol[1]).zfill(len(j))))

    def Tests(self):
        yield TestCase("""5
1? 2?
?2? ??3
? ?
?5 ?0
?11?0 1?609
""", """Case #1: 19 20
Case #2: 023 023
Case #3: 0 0
Case #4: 05 00
""")
