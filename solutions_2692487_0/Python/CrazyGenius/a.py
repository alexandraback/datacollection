cas = int(raw_input().strip())

for cc in range(1,cas+1):
    inp = raw_input().strip().split()
    now = int(inp[0])
    N = int(inp[1])
    motes = raw_input().strip().split()
    for i in range(N):
        motes[i] = int(motes[i])
    motes.sort()
    if(now == 1):
        last_ans = N
    else:
        ans = []
        for i in range(N+1):
            ans.append(0)
        for i in range(N):
            tmp = 0
            while(now <= motes[i]):
                tmp += 1
                now += now-1
            now += motes[i]
            ans[i+1] = ans[i]+tmp
        last_ans = float('Inf')
        for i in range(N+1):
            last_ans = min(last_ans,ans[i]+N-i)
    print 'Case #' + str(cc) + ': ' + str(last_ans)
