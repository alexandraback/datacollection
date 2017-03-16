# -*- coding: utf-8 -*-
"""
Created on Mon Mar 28 18:50:14 2016

@author: James
"""

import sys
import os

def get_digits(num):
    if num == 0:
        return [0]
    digits = set([])
    while num > 0:
        digits.add(num % 10)
        num = int(num // 10)
    return digits
    


def make_answer(N):
    if N == 0:
        return 'INSOMNIA'
    digits = set([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
    current = 0
    while len(digits) > 0:
        current += N
        digits = digits.difference(get_digits(current))
    return current
    
def rdln(txtin):
    return txtin.readline().strip()

def file_io():
    file_names = 'problemA'
    with open(''.join([file_names, '.in'])) as txtin:
        with open(''.join([file_names, '.out']), 'w') as txtout:
            case_count = int(rdln(txtin))
            for i in range(case_count):
                N = int(rdln(txtin))
                answer = make_answer(N)
                
                str_out = str(answer)
                txtout.write(''.join(['Case #', str(i + 1), ': ']))
                txtout.write(str_out)
                txtout.write('\n')
    osCommandString = ''.join(['notepad.exe ', file_names, '.out'])
    os.system(osCommandString)

def main():
    """Main"""
    file_io()

if __name__ == '__main__':
    sys.exit(main())
