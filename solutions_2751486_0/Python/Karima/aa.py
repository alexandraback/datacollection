#! /usr/bin/python

import sys

vokal = ['a','e','i','o','u']

def vokalkah (c):
    if c in vokal:
        return True
    return False

def adasek (teks, n):
    j = 0
    for c in teks:
        if not vokalkah(c):
            j += 1
            if j == n:
                return True
        else:
            j = 0
    return False

def hitung (nama, n):
    hasil = 0
    p = len(nama)
    for i in range(p - n + 1):
        for j in range(i + n, p + 1):
            sub = nama[i:j]
            if adasek(sub, n):
                hasil += 1
    return hasil


i = 0
nomor = 1
data = sys.stdin.readlines()
for baris in data:
    if i == 0:
        jumlahsoal = int(baris)
    else:
        nama, n =  baris.strip().split(' ')
        hasil = hitung(nama, int(n))
        jawab = "Case #" + str(nomor) + ": " + str(hasil)
        print jawab
        nomor += 1
    i += 1