#! /usr/bin/python

import sys

fas = []
fas.append(1)
fas.append(4)
fas.append(9)
fas.append(121)
fas.append(484)
fas.append(10201)
fas.append(12321)
fas.append(14641)
fas.append(40804)
fas.append(44944)
fas.append(1002001)
fas.append(1234321)
fas.append(4008004)
fas.append(100020001)
fas.append(102030201)
fas.append(104060401)
fas.append(121242121)
fas.append(123454321)
fas.append(125686521)
fas.append(400080004)
fas.append(404090404)
fas.append(10000200001)
fas.append(10221412201)
fas.append(12102420121)
fas.append(12345654321)
fas.append(40000800004)
fas.append(1000002000001)
fas.append(1002003002001)
fas.append(1004006004001)
fas.append(1020304030201)
fas.append(1022325232201)
fas.append(1024348434201)
fas.append(1210024200121)
fas.append(1212225222121)
fas.append(1214428244121)
fas.append(1232346432321)
fas.append(1234567654321)
fas.append(4000008000004)
fas.append(4004009004004)

def hitung(teks):
    j = 0
    sel = teks.split(' ')
    A = int(sel[0])
    B = int(sel[1])
    for x in fas:
        if x >= A and x <= B: j += 1
    return str(j)


i = 0
nomor = 1
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