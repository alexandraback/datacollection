from collections import defaultdict

def solve_inner(c, j):
    if '?' not in c and '?' not in j:
        return (abs(int(c) - int(j)),c,j)
    if '?' in c:
        pos = c.find('?')
        sols = []
        for i in range(10):
            c = c[:pos] + str(i) + c[pos+1:]
            sols.append(solve_inner(c, j))
    else:
        pos = j.find('?')
        sols = []
        for i in range(10):
            j = j[:pos] + str(i) + j[pos+1:]
            sols.append(solve_inner(c, j))
    return min(sols)



def solve(s):
    c,j = s.split()
    res = solve_inner(c, j)
    return ' '.join(map(str, (res[1],res[2])))

t = int(input())
for i in range(t):
    tc = input()
    sol = solve(tc)
    print('Case #{}: {}'.format(i+1, sol))

