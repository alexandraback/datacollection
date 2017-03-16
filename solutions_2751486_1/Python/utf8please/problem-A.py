#!/usr/bin/env python3

def solve(fin, fout):
    s, n = fin.readline().split()
    n = int(n)

    l = 0
    result = 0
    t = 0

    for i, c in enumerate(s):
        if c in "aeiou":
            l = 0
        else:
            l += 1
            if l >= n:
                t = i - n + 2
        result += t

    fout.write(str(result));
    fout.write('\n');
