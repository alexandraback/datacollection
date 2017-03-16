#!/usr/bin/env python3

tbl = str.maketrans("+-", "-+")

def flip(sig):
    return sig.translate(tbl)[::-1]

def solve(sig):
    n = 0
    while '-' in sig:
        sig = sig.rstrip('+')
        if sig[0] == '-' and sig[-1] == '-':
            sig = flip(sig)
            n += 1
            continue
        #simple invert, searching for ---- and inc n to count final flip
        sig = sig.translate(tbl)
        n += 1
    return n


testcases = int(input())

for case_n in range(1, testcases+1):
    #case_data = map(int, input().split())
    case_data = input().split()
    print("Case #%i: %s" % (case_n, solve(*case_data)))
