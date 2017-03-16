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

with open('c.in', 'r') as f, open('c.out', 'w') as g:
    tests = None
    numbers = None
    n = 0
    for line in f:
        line = line.rstrip()
        if tests is None:
            tests = int(line)
            continue
        n += 1
        a, b = line.split()
        a_s = get_all(a)
        b_s = get_all(b)
        a_s.sort()
        b_s.sort()
        ans_a = None
        ans_b = None
        min_ans = 1e20
        for i in a_s:
            for j in b_s:
                if abs(i[0] - j[0]) < min_ans:
                    min_ans = abs(i[0] - j[0])
                    ans_a = i[1]
                    ans_b = j[1]

        g.write('Case #' + str(n) + ': ' + str(ans_a) + ' ' + str(ans_b) + '\n')



