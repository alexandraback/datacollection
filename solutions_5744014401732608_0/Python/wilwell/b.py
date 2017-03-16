from collections import Counter
def gen(s, i, ans):
    if i == len(s):
        ans.append((int(''.join(s)), ''.join(s)))
        return
    if s[i] != '?':
        gen(s, i + 1, ans)
    else:
        for j in range(10):
            s[i] = str(j)
            gen(s, i + 1, ans)
        s[i] = '?'
def get_all(s):
    ans = []
    gen(list(s), 0, ans)
    return ans

with open('B-small-attempt1.in', 'r') as f, open('b.out', 'w') as g:
    tests = None
    n = 0
    for line in f:
        line = line.rstrip()
        if tests is None:
            tests = int(line)
            continue
        n += 1
        b, m = map(int, line.split())
        if m > 2 ** (b - 2):
            g.write('Case #' + str(n) + ': IMPOSSIBLE\n')
            continue
        else:
            g.write('Case #' + str(n) + ': POSSIBLE\n')
        matrix = [[0 for i in range(b)] for j in range(b)]
        for i in range(1, b):
            for j in range(i + 1, b):
                matrix[i][j] = 1
        if (m == 2 ** (b - 2)):
            for i in range(1, b):
                matrix[0][i] = 1
        else:
            x = bin(m)[2:][::-1]
            for i, ch in enumerate(x):
                if ch == '1':
                    matrix[0][b - i - 2] = 1
        for i in range(b):
            g.write(''.join(map(str, matrix[i])) + '\n')
