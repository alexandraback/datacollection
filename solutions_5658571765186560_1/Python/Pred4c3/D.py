T=int(input())
for case_id in range(1,T+1):
    X,R,C = map(int,list(input().split()))
    R,C = max(R,C),min(R,C)
    def solve():
        if X >= 7 or X>R or (X+1)//2>C or R*C % X != 0 or \
           (X==4 and C==2) or (X==5 and C==3 and R==5) or (X==6 and C==3):
            return 'RICHARD'
        
        return 'GABRIEL'

    ans = solve()

    print('Case #%d: %s' % (case_id, ans))
    import sys
    print('Case #%d: %s' % (case_id, ans), file=sys.stderr)
