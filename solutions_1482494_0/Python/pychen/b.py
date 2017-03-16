import operator
import functools

T = int(input())
for t in range(T):
    N = int(input())
    
    l = []
    for i in range(N):
        tmp = list(map(int, input().split()))
        l.append(tmp + [0])
    score = 0
    level = 0
    step = 0
    MAX = 10000000
    failed = False
    
    while l and not failed:
        l = sorted(l, key = lambda x: x[1] * MAX + x[0])#cmp=lambda x,y: x[1] < y[1])
        while l and l[0][1] <= score:
            score += 2 - l[0][2]
            l = l[1:]
            step += 1
        i = len(l) - 1
        while l:    
            if i < 0:
                failed = True
                break
            elif l[i][0] <= score:
                score += 1
                step += 1
                l[i][2] = 1
                l[i][0] = MAX
                break
            else:
                i -= 1

    if failed:
        print("Case #%d: Too Bad" %(t + 1))
    else:
        print("Case #%d: %d" %(t + 1, step))
