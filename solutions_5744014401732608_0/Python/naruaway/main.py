def solve(B, M):
    p = 1
    i = 0
    while True:
        if i + 2 > B:
            return ('IMPOSSIBLE', None, None)
        if p >= M:
            break
        p *= 2
        i += 1
    r = p - M
    j = 0
    cut_indicies = []
    while r != 0:
        if r & 1 == 1:
            cut_indicies.append(B - 2 - j)
        r >>= 1
        j += 1
    return ('POSSIBLE', cut_indicies, B - 2 - i)

def solve2(B, M, t):
    answer, cut_indicies, start_index = solve(B, M)
    print('Case #{}: {}'.format(t + 1, answer))
    if answer != 'POSSIBLE':
        return
    table = [[0 for _ in range(B)] for _ in range(B)]
    if start_index != 0:
        table[0][start_index] = 1
    for i in range(start_index, B):
        if i in cut_indicies:
            continue
        for j in range(i + 1, B):
            if j in cut_indicies:
                continue
            table[i][j] = 1
    for line in table:
        print(''.join(map(str, line)))



T = int(input())
for t in range(T):
    B, M = map(int, input().split())
    solve2(B, M, t)
