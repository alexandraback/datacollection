
T = int(input())


def solve(n):
    S = set()
    for i in range(1,100):
        S = S.union(set(str(n * i)))
        # print i, S
        if len(S) == 10: return n * i
    return "INSOMNIA"


for case in range(1, T + 1):
    N = input()
    print "Case #%d: %s"%(case, str(solve(N)))
