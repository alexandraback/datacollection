#!/usr/bin/python3

testsNb = int(input()) # Get input
for test in range(1, testsNb+1):
    N = int(input())
    bffs = [int(n)-1 for n in input().split()]
    result = 0

    for i in range(N):
        called = []
        called.append(i)

        index = i
        while not (bffs[index] in called):
            index = bffs[index]
            called.append(index)
        if bffs[index] == called[-2] and index in bffs:
            newIndexes = [x for x in range(len(bffs)) if bffs[x] == index]
            for newIndex in newIndexes:
                if not (newIndex in called):
                    index=newIndex
                    called.append(newIndex)
                    break;

        if len(called) > result:
            result = len(called)
            if bffs[index] != called[0] and bffs[index] != called[-2]:
                result = result-1

    print("Case #" + str(test) + ": " + str(result))
