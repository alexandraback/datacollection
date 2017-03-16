from DomainModel.TestCase import TestCase


class FractilesSolver:

    def Solve(self):
        tests = int(input())
        for test in range(tests):
            K,C,S = [int(x) for x in input().split()]
            ret = [str(1 + x*(K**(C-1))) for x in range(S)]
            print("Case #{}: {}".format(test+1,' '.join(ret)))

    def Tests(self):
        yield TestCase("""5
2 3 2
1 1 1
2 1 1
2 1 2
3 2 3
""","""Case #1: 2
Case #2: 1
Case #3: IMPOSSIBLE
Case #4: 1 2
Case #5: 2 6
""")