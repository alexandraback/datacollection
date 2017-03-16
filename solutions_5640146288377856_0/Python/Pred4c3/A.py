T=int(input())
for case_id in range(1,T+1):
    R,C,W = map(int,input().split())
    ans = (R-1) * C // W
    ans += C // W + W - (1 if C % W == 0 else 0)
    
    print('Case #%d: %d' % (case_id, ans))
    import sys
    print('Case #%d: %d' % (case_id, ans), file=sys.stderr)
