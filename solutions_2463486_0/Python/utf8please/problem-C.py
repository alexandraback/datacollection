#!/usr/bin/env python3

from math import *

def solve(fin, fout):
    a, b = map(int, fin.readline().split())
    sa = sqrt(a)
    sb = sqrt(b)
    count = 0
    if a == b and a == 1:
        count = 1
    for n in range(floor(log10(sa)) + 1, ceil(log10(sb)) + 1):
        i_min = 10 ** (ceil(n / 2) - 1)
        exceeded = False
        for i in range(i_min, i_min * 10):
            str_i = str(i)
            rev_num = '0' + str_i[0:n - len(str_i)][::-1]
            num = i * i_min * (10 if n % 2 ==0 else 1) + int(rev_num)
            num2 = num * num
            if num2 > b:
                exceeded = True
                break
            if a <= num2:
                str_num2 = str(num2)
                if str_num2 == str_num2[::-1]:
                    count += 1
        if exceeded:
            break

    fout.write(str(count) + '\n')
