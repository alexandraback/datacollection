#!/usr/bin/python3

import sys

N_MAX = 10**6
X_MAX = Y_MAX = 10000
T = int(sys.stdin.readline())
caseNum = 0

inner = [0, 1]
i = 1
while True:
    i += 2
    inner.append(2*i-1 + inner[-1])
    if (inner[-1] > N_MAX) and (len(inner) > X_MAX + Y_MAX):
        break

# print("Inner: ", inner[:10])
        
def factorial(n):
    if (n == 0) or (n == 1):
        return 1
    prod = 1
    for i in range(2, n+1):
        prod *= i
    return prod
        
def choose(n, k):
    return factorial(n) // (factorial(k) * factorial(n-k))
        
def solve(N, X, Y):
    dist = (abs(X) + abs(Y)) // 2
    height = Y + 1
    diamonds = N - inner[dist]
    side = 2*dist
    # print("Height: ", height)
    # print("Diamonds left: ", diamonds)
    # print("Side: ", side)
    if diamonds >= height + side:
        return 1.0
    if diamonds < height:
        return 0.0
    if (height > side) and (diamonds < 2*side + 1):
        return 0.0
    vsota = 0
    spodnja = 0
    for i in range(height, min(side, diamonds) + 1):
        vsota += choose(diamonds, i)
    for i in range(max(diamonds - side, 0), min(side, diamonds)+1):
        spodnja += choose(diamonds, i)
    return vsota / spodnja

# print(len(inner))

while caseNum < T:
    caseNum += 1
    N, X, Y = map(int, sys.stdin.readline().strip().split(' '))
    print("Case #{0}: {1}".format(caseNum, solve(N, X, Y)))
