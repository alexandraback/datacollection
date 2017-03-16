#!/usr/bin/python3

testsNb = int(input()) # Get input
for test in range(1, testsNb+1):
    stack = input()
    length = len(stack)
    i = length-2
    result = 0

    if stack[length-1] == "-":
        result = 1

    while i >= 0:
        if stack[i] != stack[i+1]:
            result+=1
        i-=1

    print("Case #" + str(test) + ": " + str(result))
