# -*- coding: utf-8 -*-
from math import ceil

t = int(input())

def array(r, c):
    return [['*' for j in range(c)] for i in range(r)]

for i in range(t):
    r, c, m = map(int, input().split())
    n = r*c - m


    transpose = False
    w, h = sorted([r, c])
    if r < c:
        transpose = True

    res = ""
    print("Case #" + str(i+1) + ":")
    if n == 0:
        print("Impossible")
        continue
    if n == 1:
        res = array(h, w)
        res[0][0] = 'c'
    else:
        if w == 1:
            res = array(h, w)
            res[0][0] = 'c'
            for j in range(n-1):
                res[j+1][0] = '.'
        elif w == 2:
            if n >= 4 and n % 2 == 0:
                res = array(h, w)
                res[0] = ['c', '.']
                for j in range(n // 2 - 1):
                    res[j+1] = ['.', '.']
                
            else:
                print("Impossible")
        else:
            nw = 0
            k = -1
            q = -1
            x = 3
            while True:
                if ceil(n / x) <= h:
                    nw = x
                    break
                x += 1
                if x > w:
                    break

            if nw == 0:
                print("Impossible")
            else:
                k = n // nw
                q = n % nw
                #print("n %d, nw %d, k %d, q %d" % (n, nw, k, q))

            if k >= 3:
                res = array(h, w)
                for j in range(k):
                    for j2 in range(nw):
                        res[j][j2] = '.'
                for j in range(q):
                    res[k][j] = '.'
                res[0][0] = 'c'
                if q == 1:
                    res[k-1][nw-1] = '*'
                    res[k][q] = '.'

            elif k == 2:
                if q != 1:
                    res = array(h, w)
                    for j in range(k):
                        for j2 in range(nw):
                            res[j][j2] = '.'
                    for j in range(q):
                        res[k][j] = '.'
                    res[0][0] = 'c'
                else:
                    print("Impossible")
            elif k == 1:
                if nw == 3 and q == 1:
                    res = array(h, w)
                    for j in range(2):
                        for j2 in range(2):
                            res[j][j2] = '.'
                    res[0][0] = 'c'
                else:
                    print("Impossible")
            elif k == 0:
                if n == 1:
                    res = array(h, w)
                    res[0][0] = 'c'
                else:
                    print("Impossible")

    if res:
        print("\n".join("".join(r) for r in (zip(*res) if transpose else res)))
            
        pocetmin = 0
        for r in res:
            for x in r:
                if x == '*':
                    pocetmin += 1
        if pocetmin != m:
            print("CHYBA")
            exit(1)
            
            
            
        

