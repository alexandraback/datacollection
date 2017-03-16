import sys

def solveIt():
    s = input() + '+'
    n = len(s)
    return sum([s[i] != s[i+1] for i in range(n-1)])

n_cases = int(input())
for test_case in range(1, n_cases + 1):
    
    print(test_case, file=sys.stderr, end=' ')
    res = solveIt()
    print('Case #' + str(test_case) + ':', res)

print(file=sys.stderr)
    
