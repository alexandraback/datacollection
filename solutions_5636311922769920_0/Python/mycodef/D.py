#!python3


def from_base(base, l):
    ans = 0
    for x in l:
        ans = (ans + x) * base
    return ans // base


def magic(Z, n):
    if Z == 1:
        return [from_base(n, [i]) for i in range(n)]
    ind = list(range(n)) if n % Z == 1 else list(range(1, n))
    l = len(ind)
    g_len = [l % Z, *[Z] * (l // Z)]
    m = len(g_len)
    num = [[] for i in range(m)]
    cur = 0
    for i in ind:
        if len(num[cur]) == g_len[cur]:
            cur += 1
        num[cur].append(i)

    return [from_base(n, x) for x in num]

inp = open('D-small-attempt0.in', 'r')
out = open('output.txt', 'w')

for i in range(int(inp.readline())):
    n, Z, S = list(map(int, inp.readline().split()))
    ans = magic(Z, n)
    if len(ans) > S:
        out.write('Case #{}: IMPOSSIBLE\n'.format(i + 1))
    else:
        out.write('Case #{}: {}\n'.format(i + 1, ' '.join(str(x + 1) for x in ans)))