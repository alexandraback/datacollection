import sys

def solve(line):
    b,m = [int(s) for s in line.split(' ')]
    slides = 0
    mat = [[1 if j == i+1 else 0 for j in range(b)] for i in range(b)]
    m -= 1
    acc = [1 for i in range(b)]
    for i in range(2,b):
        acc[i] = acc[i-1]
        for j in range(i-2, -1, -1):
            if m >= acc[j]:
                m -= acc[j]
                acc[i] += acc[j]
                mat[b-i-1][b-i-1+(i-j)] = 1
    if m == 0:
        sol = 'POSSIBLE'
        for row in mat:
            sol += '\n'
            sol += ''.join(str(i) for i in row)
        return sol
    else:
        return 'IMPOSSIBLE'

case = 0
next(sys.stdin)
for line in sys.stdin:
    line = line.strip()
    case += 1
    print('Case #{}: {}'.format(case, solve(line)))
