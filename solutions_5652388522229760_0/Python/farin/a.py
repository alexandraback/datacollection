#!/usr/bin/env python3

def solve(n):
    if n == 0:
        return "INSOMNIA"
    seen = set(str(n))
    nstr = str(n)
    nstr_strip = nstr.rstrip("0")
    n = int(nstr_strip)
    i = n
    while len(seen) < 10:
        i += n
        seen.update(str(i))
    return str(i) + ("0" * (len(nstr) - len(nstr_strip)))


testcases = int(input())

for case_n in range(1, testcases+1):
    case_data = map(int, input().split())
    #case_data = input().split()
    print("Case #%i: %s" % (case_n, solve(*case_data)))
