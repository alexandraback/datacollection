T=int(input())
for case_id in range(1,T+1):
    S = list(map(int,list(input().split()[1])))
    ans,stand = 0,0
    for i in range(len(S)):
        if S[i]>0 and i > stand:
            guest = i - stand
            stand += guest
            ans += guest
        stand += S[i]
    print('Case #%d: %d' % (case_id, ans))
    import sys
    print('Case #%d: %d' % (case_id, ans), file=sys.stderr)
