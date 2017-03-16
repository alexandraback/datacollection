def estimate(j):
    global A
    if A > sizes[j]:
        A += sizes[j]
        return 0
    i = 0
    while i < N+1:
        A += A-1
        i +=1
        if A > sizes[j]:
            break
    A +=sizes[j]
    return i

T = input()
for i in range(T):
    A, N = [int(x) for x in raw_input().split()]
    sizes = [int(x) for x in raw_input().split()]
    sizes.sort()
    steps = [0 for x in range(N)]
    for j in range(N):
        steps[j] = estimate(j)

    minsteps = N
    nowsteps = 0
    for j in range(N):
        nowsteps += steps[j]
        if nowsteps + N - j - 1 < minsteps:
            minsteps = nowsteps + N - j - 1
    print 'Case #'+str(i+1)+': '+str(minsteps) 
