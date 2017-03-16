def mul(x, y):
    t = {
        ('i', 'j'): 'k',
        ('j', 'k'): 'i',
        ('k', 'i'): 'j'
    }
    s = x[1]*y[1]
    if x[0] == '1': 
        f = y[0]
    elif y[0] == '1': 
        f = x[0]
    elif x[0] == y[0]:
        f = '1'
        s *= -1
    elif (x[0], y[0]) in t:
        f = t[x[0], y[0]]
    else:
        f = t[y[0], x[0]]
        s *= -1
    return (f, s)

def solve(s):
    p = ('1', 1)
    v1 = [p]
    for c in s:
        p = mul(p, (c, 1))
        v1.append(p)
    p = ('1', 1)
    v2 = [p]
    for c in reversed(s):
        p = mul((c, 1), p)
        v2.append(p)
    v2.reverse()
    flag = False
    for p1, p2 in zip(v1, v2):
        if not flag:
            flag = (p1 == ('i', 1))
        elif p1 == p2 == ('k', 1):
            return True
    return False

t = int(input())
output = 'Case #{}: {}'
for i in range(t):
    l, x = map(int, input().split())
    s = input()
    s *= min(x, 12 + x%4)
    print(output.format(i + 1, 'YES' if solve(s) else 'NO'))
