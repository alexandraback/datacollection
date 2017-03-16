#!/usr/bin/env python3

def solve(fin, fout):
    n, m = map(int, fin.readline().split())
    lawn = [list(map(int, fin.readline().split())) for i in range(n)]

    for i in range(n):
        for j in range(m):
            flag = True
            for k in range(n):
                if lawn[k][j] > lawn[i][j]:
                    flag = False
                    break
            if not flag:
                flag = True
                for k in range(m):
                    if lawn[i][k] > lawn[i][j]:
                        flag = False
                        break
                if not flag:
                    fout.write('NO\n')
                    return

    fout.write('YES\n')

