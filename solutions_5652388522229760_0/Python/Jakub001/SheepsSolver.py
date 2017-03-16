from DomainModel.TestCase import TestCase

class SheepSolver:
    def Solve(self):
            n = int(input())
            for test in range(n):
                val = int(input())
                ret='INSOMNIA'
                x = 0
                if val>0:
                    s=set()
                    while True:
                        x+=val
                        s=s.union([c for c in str(x)])
                        if len(s)==10:
                            break
                    ret = str(x)
                print("Case #{}: {}".format(test+1,ret))

    def Tests(self):
        yield TestCase("""5
0
1
2
11
1692
""","""Case #1: INSOMNIA
Case #2: 10
Case #3: 90
Case #4: 110
Case #5: 5076
""")