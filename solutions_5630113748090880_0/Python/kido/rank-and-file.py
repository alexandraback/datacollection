#!/usr/bin/python3

testsNb = int(input()) # Get input
for test in range(1, testsNb+1):
    height = int(input())
    lines = [input().split() for i in range(2*height-1)]
    missing = []
    counter = [0 for x in range(1, 2501)]

    for line in lines:
        for nb in line:
            counter[int(nb)] +=1
    for case in range(1, 2500):
        if counter[case]%2 == 1:
            missing.append(case)

    missing.sort()
    missingStr = [str(i) for i in missing]

    print("Case #" + str(test) + ": " + ' '.join(missingStr))
