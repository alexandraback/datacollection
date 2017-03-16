# Encoding: utf-8
'''
Created on 13.04.2013

@author: Los

@version: 0.0.1
'''
import sys


def check(lines):
    if lines[0] == 0b1111:
        return 1
    if lines[1] == 0b1111:
        return 1
    if lines[2] == 0b1111:
        return 1
    if lines[3] == 0b1111:
        return 1
    l = (lines[0] & 0b1000) | ((lines[1] & 0b1000) >> 1) | ((lines[2] & 0b1000) >> 2) | ((lines[3] & 0b1000) >> 3)
    if l == 0b1111:
        return 1
    l = ((lines[0] & 0b0100) << 1) | ((lines[1] & 0b0100) >> 0) | ((lines[2] & 0b0100) >> 1) | ((lines[3] & 0b0100) >> 2)
    if l == 0b1111:
        return 1
    l = ((lines[0] & 0b0010) << 2) | ((lines[1] & 0b0010) << 1) | ((lines[2] & 0b0010) << 0) | ((lines[3] & 0b0010) >> 1)
    if l == 0b1111:
        return 1
    l = ((lines[0] & 0b0001) << 3) | ((lines[1] & 0b0001) << 2) | ((lines[2] & 0b0001) << 1) | ((lines[3] & 0b0001) >> 0)
    if l == 0b1111:
        return 1
    l = (lines[0] & 0b1000) | (lines[1] & 0b0100) | (lines[2] & 0b0010) | (lines[3] & 0b0001)
    if l == 0b1111:
        return 1
    l = (lines[0] & 0b0001) | (lines[1] & 0b0010) | (lines[2] & 0b0100) | (lines[3] & 0b1000)
    if l == 0b1111:
        return 1
    return 0
    
    

def main(argv=None):
    if argv==None : argv=sys.argv

    import locale
    locale.setlocale(locale.LC_ALL, '')

    T = int(input())
    for i in range(1, T + 1):
        lines = list()
        lines.append(input().strip())
        lines.append(input().strip())
        lines.append(input().strip())
        lines.append(input().strip())
        input()
        # check X
        lx = list()
        lx.append(int('0b' + lines[0].replace('.', '0').replace('X', '1').replace('O', '0').replace('T', '1'), 2))
        lx.append(int('0b' + lines[1].replace('.', '0').replace('X', '1').replace('O', '0').replace('T', '1'), 2))
        lx.append(int('0b' + lines[2].replace('.', '0').replace('X', '1').replace('O', '0').replace('T', '1'), 2))
        lx.append(int('0b' + lines[3].replace('.', '0').replace('X', '1').replace('O', '0').replace('T', '1'), 2))
        if check(lx) == 1:
            print('Case #{}: X won'.format(i))
            continue
        lx = list()
        lx.append(int('0b' + lines[0].replace('.', '0').replace('X', '0').replace('O', '1').replace('T', '1'), 2))
        lx.append(int('0b' + lines[1].replace('.', '0').replace('X', '0').replace('O', '1').replace('T', '1'), 2))
        lx.append(int('0b' + lines[2].replace('.', '0').replace('X', '0').replace('O', '1').replace('T', '1'), 2))
        lx.append(int('0b' + lines[3].replace('.', '0').replace('X', '0').replace('O', '1').replace('T', '1'), 2))
        if check(lx) == 1:
            print('Case #{}: O won'.format(i))
            continue
        if lines[0].count('.') > 0:
            print('Case #{}: Game has not completed'.format(i))
            continue
        if lines[1].count('.') > 0:
            print('Case #{}: Game has not completed'.format(i))
            continue
        if lines[2].count('.') > 0:
            print('Case #{}: Game has not completed'.format(i))
            continue
        if lines[3].count('.') > 0:
            print('Case #{}: Game has not completed'.format(i))
            continue
        print('Case #{}: Draw'.format(i))



if __name__ == '__main__':
    main()
