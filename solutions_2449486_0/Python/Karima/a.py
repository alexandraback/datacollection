#! /usr/bin/python

import sys

def ambilkolom(matrix, i):
    return [baris[i] for baris in matrix]

def hitung(matrix, jb, jk):
    # ambil nilai max per baris dan per kolom
    bmax = []
    kmax = []
    for b in range(0, jb):
        bmax.append(max(matrix[b]))
    for k in range(0, jk):
        temp = ambilkolom(matrix, k)
        kmax.append(max(temp))
    # print bmax, kmax
    # loop per item di matrix
    for b in range(0, jb):
        for k in range(0, jk):
            x = matrix[b][k]
            bisa = True
            if x < bmax[b] and x < kmax[k]:
                bisa = False
            if not bisa:
                return 'NO'
    return 'YES'


i = 0
j = 0
dimensi = ''
nomor = 1
data = sys.stdin.readlines()
for baris in data:
    if i == 0:
        jumlahsoal = int(baris)
    elif dimensi == '':
        dimensi = baris.strip()
        barkol = dimensi.split(' ')
        jb = int(barkol[0])
        jk = int(barkol[1])
        matrix = []
    else:
        baris = baris.strip()
        sels = baris.split(' ')
        x = []
        for s in sels:
            x.append(int(s))
        matrix.append(x)
        j += 1
        if j == jb:
            if jb == 1 or jk == 1:
                hasil = 'YES'
            else:
                hasil = hitung(matrix, jb, jk)
            jawab = "Case #" + str(nomor) + ": " + hasil
            print jawab
            j = 0
            dimensi = ''
            nomor += 1
    i += 1