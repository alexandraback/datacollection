#!/usr/bin/env pypy3

t = int(input())
for caso in range(1, t + 1):
    lista = input().split(" ")
    k = int(lista[0])
    c = int(lista[1])
    s = int(lista[2])
    tot = k ** (c - 1)
    print("Case #", caso, ": ", sep='', end='')
    for i in range(k):
        print((tot * i) + 1, " ", sep='', end='')
    print()
