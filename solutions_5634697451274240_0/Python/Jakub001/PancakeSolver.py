from DomainModel.TestCase import TestCase

class PancakeSolver:
    def Solve(self):
            n = int(input())
            for test in range(n):
                a = [x=='+' for x in input().strip()]
                n = len(a)
                cnt=0
                for i in range(1,n):
                    if a[i]!=a[i-1]:
                        cnt+=1
                        a[i-1] = not a[i-1]
                if not a[n-1]:
                    cnt+=1
                print("Case #{}: {}".format(test+1,cnt))

    def Tests(self):
        yield TestCase("""5
-
-+
+-
+++
--+-
""","""Case #1: 1
Case #2: 1
Case #3: 2
Case #4: 0
Case #5: 3
""")