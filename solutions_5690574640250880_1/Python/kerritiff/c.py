def deal(r, c, m, rb, bb):
    if c == 1:
        if r == m + 1:
            return [['c']] + [['*'] for i in range(m)]
        if rb:
            return False
        else:
            return [['c']] + [['.'] for i in range(r-m-1)] + [['*'] for i in range(m)]
    if r == 1:
        if c == m + 1:
            return [['c'] + ['*']*m]
        if bb:
            return False
        else:
            return [['c'] + ['.']*(c-m-1) + ['*']*m]

    ans = [['.']*c for i in range(r)]
    if m == 0:
        ans[0][0] = 'c'
        return ans

    if min(r, c) == 2:
        return False

    if m <= r - 2:
        ans[0][0] = 'c'
        for i in range(r-1, r-1-m, -1):
            ans[i][-1] = '*'
        return ans
    if m <= c - 2:
        ans[0][0] = 'c'
        for i in range(c-1, c-1-m, -1):
            ans[-1][i] = '*'
        return ans
    
    if r == 3:
        return False

    ans[0][0] = 'c'
    i = m-1; x = r-1; y = c-1
    ans[x][y] = '*'
    while i > 0:
        i -= 1
        if x >= y:
            x -= 1
            ans[x][c-1] = '*'
        else:
            y -= 1
            ans[r-1][y] = '*'
    return ans

def search(r, c, m, rb, bb):
    #print 'search', r, c, m
    if r >= c:
        if m >= c:
            ans = search(r-1, c, m-c, rb, 1)
            if not ans:
                return ans
            #print 'result:', ans + [['*'] for i in range(c)]
            return ans + [['*']*c]
    else:
        if m >= r:
            ans = search(r, c-1, m-r, 1, bb)
            if not ans:
                return ans

            #print 'result2:', [x + ['*'] for x in ans]
            return [x + ['*'] for x in ans]
    ans = deal(r, c, m, rb, bb)
    #print 'deal:', ans
    return ans

def solve():
    r, c, m = map(int, raw_input().split())
    
    return search(r, c, m, 0, 0)

def main():
    t = int(raw_input())
    for i in xrange(1, t+1):
        s = solve()
        print 'Case #%s:' % i
        if s is False:
            print 'Impossible'
            continue
        #print 's=', s
        for r in s:
            print ''.join(r)

if __name__ == '__main__':
    main()
