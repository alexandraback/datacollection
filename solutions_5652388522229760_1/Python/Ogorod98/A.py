#!/usr/bin/python3

def solve():
    n = int(input())
    if n == 0:
        return "INSOMNIA"
    s = n
    digits = set()
    for d in str(s):
        digits.add(d)
    while len(digits) < 10:
        s += n
        for d in str(s):
            digits.add(d)
    return s



t = int(input())

for i in range(t):
    print("Case #{}:".format(i + 1), solve())
