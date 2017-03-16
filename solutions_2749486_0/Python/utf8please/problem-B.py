#!/usr/bin/env python3

def solve(fin, fout):
    x, y = list(map(int, fin.readline().split()))

    if x > 0:
        fout.write('WE' * (x))
    elif x < 0:
        fout.write('EW' * (-x))

    if y > 0:
        fout.write('SN' * (y))
    elif y < 0:
        fout.write('NS' * (-y))

    fout.write('\n')
