T=int(input())
for case_id in range(1,T+1):
    C,D,V = map(int,input().split())
    coins = list(map(int,input().split()))
    '''req = [1]
    while req[-1]*(D+1) <= V:
        req.append(req[-1]*(D+1))
    print(req)'''

    ans,do = 0,0
    while do < V:
        if len(coins)>0 and coins[0] <= do+1:
            do = C*coins[0] + do
            coins.pop(0)
        else:
            ans += 1
            do = C*(do+1) + do

    print('Case #%d: %d' % (case_id, ans))
    import sys
    print('Case #%d: %d' % (case_id, ans), file=sys.stderr)
