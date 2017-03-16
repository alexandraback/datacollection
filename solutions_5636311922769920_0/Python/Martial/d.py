import sys

def solveIt():

    K, C, S = map(int, input().split())
    if C * S < K:
        return 'IMPOSSIBLE'
    t = []
    for i in range(0, K, C):
        t.append([(i+j) % K for j in range(C)])

    def f(v):

        s = 1
        p = 1
        for i in range(C):
            s += v[i] * p
            p *= K
        return s

    res = map(str, [f(v) for v in t])
    return ' '.join(res)

n_cases = int(input())
for test_case in range(1, n_cases + 1):
    
    print(test_case, file=sys.stderr, end=' ')
    res = solveIt()
    print('Case #' + str(test_case) + ':', res)

print(file=sys.stderr)
    
