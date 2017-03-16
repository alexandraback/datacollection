# -*- coding: utf-8 -*-
"""
Created on Mon Mar 28 18:50:14 2016

@author: James
"""

import sys
import os
import math

def make_answer_trivial(K, C, S):
    if S >= K:
        return [i + 1 for i in range(K)]
        
def K_powers(K, C):
    return [K**i for i in range(C + 1)]
        
def make_answer(K, C, S):
    if S < math.ceil(K / C):
        return 'IMPOSSIBLE'
    tiles = []
    k_powers = K_powers(K, C)
    tile = 1
    for i in range(1, K):
        if i % C == 0:
            tiles.append(tile)
            tile = 1
        tile += i * k_powers[(C - 1 - i) % C]
    tiles.append(tile)
    return tiles
    
def rdln(txtin):
    return txtin.readline().strip()

def file_io():
    file_names = 'problemD'
    with open(''.join([file_names, '.in'])) as txtin:
        with open(''.join([file_names, '.out']), 'w') as txtout:
            case_count = int(rdln(txtin))
            for i in range(case_count):
                K, C, S = (int(x) for x in rdln(txtin).split())
                answer = make_answer(K, C, S)
                if not isinstance(answer, str):
                    answer = ' '.join([str(x) for x in answer])
                str_out = answer
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
