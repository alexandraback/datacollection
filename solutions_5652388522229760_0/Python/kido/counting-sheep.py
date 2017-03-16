#!/usr/bin/python3

testsNb = int(input()) # Get input
for test in range(1, testsNb+1):
    N = int(input())
    if N != 0:
        digits = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        currentValue=N
        while 0 in digits:
            for char in str(currentValue):
                digits[int(char)] = 1
            currentValue += N

        print("Case #" + str(test) + ": " + str(currentValue-N))
    else:
        print("Case #" + str(test) + ": INSOMNIA")
