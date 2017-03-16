import sys

def f(s):
    n = len(s)
    t = s[0]
    for i in range(1,n):
        if s[i] + t > t + s[i]:
            t = s[i] + t
        else:
            t = t + s[i]
    return t

n_cases = int(input())
for test_case in range(1, n_cases + 1):
    s = input()
    print(test_case, file=sys.stderr, end=' ')
    res = f(s)
    print('Case #' + str(test_case) + ':', res)

print(file=sys.stderr)
    
