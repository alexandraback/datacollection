T=int(input())
for case_id in range(1,T+1):
    R,C,M = map(int,input().split()) #x:C y:R
    dirs = [-1,0,1]

    mx = [['*']*C for y in range(R)]

    def get_bombs(x,y):
        res = []
        for cy in dirs:
            for cx in dirs:
                if 0<=x+cx<C and 0<=y+cy<R and mx[y+cy][x+cx] == '*':
                    res.append((x+cx,y+cy))
        return res

    def remove_bombs(bombs):
        for bomb in bombs:
            mx[bomb[1]][bomb[0]] = '.'

    def get_table():
        res = ''
        for y in range(R):
            res += '\n' + ''.join(mx[y])
        return res

    def solve():
        N = R*C-M
        if N == 1:
            mx[0][0]='c'
            return get_table()
        bombs = get_bombs(0,0)
        remove_bombs(bombs)
        N -= len(bombs)
        mx[0][0]='c'

        if N < 0:
            return '\nImpossible'
        elif N == 0:
            return get_table()

        for y in range(R):
            for x in range(C):
                bombs = get_bombs(x, y if x != 0 else y + 1)
                if len(bombs) <= N:
                    remove_bombs(bombs)
                    N -= len(bombs)
                if N == 0:
                    return get_table()
        return '\nImpossible'

    ans = solve()
    
    print('Case #%d: %s' % (case_id, ans))
    import sys
    print('Case #%d: %s (R:%d C:%d M:%d)' % (case_id, ans, R, C, M), file=sys.stderr)
