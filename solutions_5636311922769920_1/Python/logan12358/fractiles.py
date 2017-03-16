t = int(input())

for _i in range(1, t+1):
    print("Case #%d: "%_i, end='')
    k, c, s = map(int, input().split())
    if s*c < k:
        print("IMPOSSIBLE")
    else:
        test=[d for d in range(k)]
        soln=[]
        while len(test)>0:
            x=1
            for j in range(c):
                x+=test.pop()*(k**j)
                if len(test)==0:
                    break
            soln.append(x)
        print(' '.join(map(str, soln)))
