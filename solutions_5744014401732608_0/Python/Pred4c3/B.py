import sys
T=int(input())
for case_id in range(1,T+1):
    B,M=map(int,input().split())
    def solve():

        f = 1
        s = 1
        while f<=M:
            f *= 2
            s += 1
        f//=2
        print('fs', f,s, file=sys.stderr)
        if s>B:
            return 'IMPOSSIBLE'

        mx = [[0]*B for _ in range(B)]
        for y in range(s):
            for x in range(s):
                if x>y:
                    mx[y][x] = 1
        rem = M
        print('rem', rem, file=sys.stderr)
        for y in range(s-1,-1,-1):
            v = 2**y
            if v<=rem:
                rem-=v
                mx[y][B-1]=1
                print('rem y', rem, y, file=sys.stderr)

        assert(rem==0)

        return 'POSSIBLE\n' + '\n'.join(''.join(map(str,r)) for r in mx)

    ans = solve()
    print('Case #%d: %s' % (case_id, ans))
    print('Case #%d: %s' % (case_id, ans), file=sys.stderr)
