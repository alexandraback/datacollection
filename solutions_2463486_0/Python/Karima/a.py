#! /usr/bin/python

import sys

def palindromkah (angka):
    teks = str(angka)
    p = len(teks)
    if p == 1:
        return True
    if p == 2:
        if teks[0] == teks[1]:
            return True
        else:
            return False
    if p == 3:
        if teks[0] == teks[2]:
            return True
        else:
            return False


def buatdaftarfas ():
    fas = []
    for i in range(1, 35):
        if palindromkah(i):
            x = i * i
            if x > 1000:
                break
            if palindromkah(x):
                fas.append(x)
    #print fas
    return fas


def hitung(teks):
    j = 0
    sel = teks.split(' ')
    A = int(sel[0])
    B = int(sel[1])
    for x in range(A, B+1):
        if x in fas: j += 1
    return str(j)


i = 0
nomor = 1
fas = buatdaftarfas()
data = sys.stdin.readlines()
for baris in data:
    if i == 0:
        jumlahsoal = int(baris)
    else:
        baris = baris.strip()
        hasil = hitung(baris)
        jawab = "Case #" + str(nomor) + ": " + hasil
        print jawab
        nomor += 1
    i += 1