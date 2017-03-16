#! /usr/bin/python

import sys

def loncat (awal, tujuan, sumbu):
    hasil = ''
    total = 0
    #print "awal", awal
    l = awal
    if sumbu == 'x':
        arahplus = 'E'
        arahminus = 'W'
    if sumbu == 'y':
        arahplus = 'N'
        arahminus = 'S'
    while total != tujuan:
        if (total + l) > tujuan:
            total -= l
            hasil += arahminus
        else:
            total += l
            hasil += arahplus
        l += 1
        if l > 500:
            break
    return (hasil, l)


def hitung (x, y):
    hasil = ''
    #print x, y
    l = 1
    if abs(y) > abs(x):
        h = loncat (1, x, 'x')
        hasil += h[0]
        h = loncat (h[1], y, 'y')
        hasil += h[0]
    else:
        h = loncat (1, y, 'y')
        hasil += h[0]
        h = loncat (h[1], x, 'x')
        hasil += h[0]
    return hasil

i = 0
nomor = 1
data = sys.stdin.readlines()
for baris in data:
    if i == 0:
        jumlahsoal = int(baris)
    else:
        x, y = baris.strip().split(' ')
        hasil = hitung(int(x), int(y))
        jawab = "Case #" + str(nomor) + ": " + str(hasil)
        print jawab
        nomor += 1
    i += 1