#!/usr/bin/env python3

n = int(input())
for i in range(n):
    print("Case #", end='')
    print(i+1, end='')
    print(": ", end='')

    x = input().split()
    b = int(x[0])
    m = int(x[1])

    if m > ((2**(b-2))):
        print("IMPOSSIBLE")
    else:
        print("POSSIBLE")
        ans = [[0 for j in range(b)] for i in range(b)]

        j = 1
        while m > 0:
            if m % 2 == 1:
                ans[0][j] = 1
            m = m//2
            j+=1

        if ans[0][b-1] == 1:
            for i in range(0,b):
                ans[0][i] = 1
            ans[0][b-1] = 0


        for j in range(1, b-1):
            for k in range(j):
                ans[b-j-1][k] = 1

        for i in range(b):
            for j in range(b):
                print(ans[i][b-j-1], end='')
            print('')
