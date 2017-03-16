#! /usr/bin/python

import sys

def hitung(teks):
    pola = [''] * 10
    pola[0] = teks[0:4]
    pola[1] = teks[4:8]
    pola[2] = teks[8:12]
    pola[3] = teks[12:16]
    pola[4] = teks[0] + teks[4] + teks[8]  + teks[12]
    pola[5] = teks[1] + teks[5] + teks[9]  + teks[13]
    pola[6] = teks[2] + teks[6] + teks[10] + teks[14]
    pola[7] = teks[3] + teks[7] + teks[11] + teks[15]
    pola[8] = teks[0] + teks[5] + teks[10] + teks[15]
    pola[9] = teks[3] + teks[6] + teks[9]  + teks[12]
    gameover = True
    if teks.count('.') > 0:
        gameover = False
    for s in pola:
        if s.count('X') == 4: return 'X won'
        if s.count('X') == 3 and s.count('T') == 1: return 'X won'
        if s.count('O') == 4: return 'O won'
        if s.count('O') == 3 and s.count('T') == 1: return 'O won'
    if gameover:
        return 'Draw'
    else:
        return 'Game has not completed'


i = 0
r = 0
pola = ''
nomor = 1
data = sys.stdin.readlines()
for baris in data:
    if i == 0:
        jumlahsoal = int(baris)
    elif len(baris) > 2:
        pola += baris.strip()
        r += 1
        if r == 4:
            hasil = hitung(pola)
            jawab = "Case #" + str(nomor) + ": " + hasil
            print jawab
            r = 0
            pola = ''
            nomor += 1
    i += 1