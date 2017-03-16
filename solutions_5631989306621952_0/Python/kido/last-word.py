#!/usr/bin/python3

testsNb = int(input()) # Get input
for test in range(1, testsNb+1):
    S = input()

    result = S[0]
    for letter in S[1::]:
        if letter >= result[0]:
            result = letter + result
        else:
            result = result + letter

    print("Case #" + str(test) + ": " + str(result))
