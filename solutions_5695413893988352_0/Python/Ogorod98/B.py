#!/usr/bin/python3

def digit(n, pos):
    return (n // 10 ** pos) % 10

def match(n, mask):
    for i in range(len(mask)):
        c = mask[-(i+1)]
        if c == '?':
            continue
        d = ord(c) - ord('0')
        if digit(n, i) != d:
            return False
    return True

def solve():
    C, J = input().split()
    best_c = -1
    best_j = -1
    best_diff = 10 ** 100
    for c in range(10 ** len(C)):
        for j in range(10 ** len(J)):
            if match(c, C) and match(j, J) and abs(c - j) < best_diff:
                best_diff = abs(c - j)
                best_c = c
                best_j = j
    return ' '.join([str(10 ** len(C) + best_c)[1:], str(10 ** len(J) + best_j)[1:]])

n = int(input())

for i in range(n):
    print("Case #{}:".format(i + 1), solve())
