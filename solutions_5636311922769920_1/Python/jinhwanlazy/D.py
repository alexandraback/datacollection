def small(K, C, S):
    return range(1, K**C+1, K**(C-1))


def show(K, C, S):
    res = []
    for g in range(K):
        seed = (['L']*(K-1))
        seed.insert(g, 'G')
        res.append(inflate(seed, C))
    for row in res:
        print(row)

def inflate(seed, C):
    prv, nxt = ['L'], []
    for _ in range(C):
        for i in prv:
            if i == 'L':
                nxt += seed.copy()
            else:
                nxt += ['G']*len(seed)
        prv, nxt = nxt, []
    return ''.join(prv)

def pos(K, C, i):
    ret = 0
    for j in range(C-1):
        ret += (C*i+j) * K**(C-1-j)
    ret += (i+1)*C
    return ret

def solve(K, C, S):
    if K == 1:
        return '1'
    if S < K / C:
        return 'IMPOSSIBLE'
    ans = []
    for i in range(K//C):
        ans.append(pos(K, C, i))
    if K % C:
        ans.append(K**C - pos(K, C, 0) + 1)
    return ' '.join(map(str, ans))

for case in range(int(input())):
    K, C, S = map(int, input().split())
    print('Case #%d:' % (case+1), solve(K, C, S))
