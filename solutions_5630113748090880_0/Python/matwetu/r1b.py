from collections import Counter

def solve(s):
    c = Counter()
    for i in s:
        for j in i:
            c[j] += 1
    return ' '.join(map(str,sorted([i for i in c if c[i] % 2 == 1])))
M=int(input())
for caseid in range(1, M+1):
    N = int(input())
    S = []
    for line in range(2*N - 1):
        S.append(list(map(int,input().strip().split())))
    print("Case #%d: %s" % (caseid, solve(S)))