T = int(input())
for testNo in range(T):
    B, M = list(map(int, input().split()))

    if M >= B:
        print("Case #%i: IMPOSSIBLE" % (testNo+1))
        continue

    layout = [[0]*B for _ in range(B)]
    currentPaths = 0

    for i in range(B-1):
        layout[i][i+1] = 1
    currentPaths += 1


    for i in range(0, B-1):
        layout[i][B-1] = 1
        currentPaths += 1

        if currentPaths == M:
            break


    print("Case #%i:" % (testNo+1))
    for elem in layout:
        print (''.join(list(map(str,elem))))