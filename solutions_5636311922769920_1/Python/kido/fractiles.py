#!/usr/bin/python3

testsNb = int(input()) # Get input
for test in range(1, testsNb+1):
    infos = [int(n) for n in input().split()]
    K = infos[0]
    C = infos[1]
    S = infos[2]

    if C > 1 and S >= K-1:
        if K > 1:
            print("Case #" + str(test) + ": " + " ".join([str(x) for x in range(2, K+1)]))
        else:
            print("Case #" + str(test) + ": 1")
    elif C ==1 and S >= K:
        print("Case #" + str(test) + ": " + " ".join([str(x) for x in range(1, K+1)]))
    else:
        print("Case #" + str(test) + ": IMPOSSIBLE")
