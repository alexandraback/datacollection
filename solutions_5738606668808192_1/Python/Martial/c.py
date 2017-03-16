import sys

def solveIt():
    N, J = map(int, input().split())
    res = []
    for S in range(J):
        s = bin(S)[2:].zfill(N // 2 - 1)
        u = '1' + ''.join([l * 2 for l in s]) + '1'
        divisors = [str(b + 1) for b in range(2, 11) ]
        line = ' '.join([u] + divisors)
        res.append(line)
    return '\n' + '\n'.join(res) + '\n'

n_cases = int(input())
for test_case in range(1, n_cases + 1):
    
    print(test_case, file=sys.stderr, end=' ')
    res = solveIt()
    print('Case #' + str(test_case) + ':', res)

print(file=sys.stderr)
    
