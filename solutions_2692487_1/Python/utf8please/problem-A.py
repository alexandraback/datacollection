#!/usr/bin/env python3

def solve(fin, fout):
    a, n = list(map(int, fin.readline().split()))
    motes = list(map(int, fin.readline().split()))
    
    motes.sort()
    op = 0
    mi = n
    for i in range(n):
        if motes[i] < a:
            a += motes[i]
        else:
            if op + n - i < mi:
                mi = op + n - i
            if a <= 1:
                op = mi
                break
            while a <= motes[i]:
                a = a * 2 - 1
                op += 1
                #print(a)
            a += motes[i]

    fout.write(str(min([op, mi])));
    fout.write('\n');
