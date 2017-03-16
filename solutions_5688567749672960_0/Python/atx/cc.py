#! /usr/bin/python3

import sys

tests = []

with open(sys.argv[1]) as f:
    for l in f:
        tests.append(int(l))
    tests = tests[1:]

def rev(i):
    return int(str(i)[::-1])


for k, N in enumerate(tests):
    i = 1
    cnt = 1
    while i < N and N != 1:
        i += 1
        cnt += 1
        if rev(i + 1) > N and rev(i) <= N and rev(i) > i:
            i = rev(i)
            cnt += 1
    print("Case #%d: %d" % (k + 1, cnt), flush = True)
