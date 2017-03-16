# -*- coding: utf-8 -*-
"""
Created on Mon Mar 28 18:50:14 2016

@author: James
"""

import sys
import os

def flip_pancakes(stack, end):
    flipped_chain = stack[:end + 1]
    for i, cake in enumerate(reversed(flipped_chain)):
        stack[i] = cake ^ 1

def end_of_chain(stack, size):
    for i in range(size - 1):
        if stack[i + 1] != stack[i]:
            return i
    return -1

def least_flips(stack):
    count, size = 0, len(stack)
    end = end_of_chain(stack, size)
    while end >= 0 and end < size:
        flip_pancakes(stack, end)
        count += 1
        end = end_of_chain(stack, size)
    if stack[0] == 1:
        return count
    else:
        return count + 1
        
def pancake_string_to_list(string):
    def char_to_digit(char):
        if char == '+':
            return 1
        else:
            return 0
    return [char_to_digit(char) for char in string]

def make_answer(string):
    pancake_list = pancake_string_to_list(string)
    return least_flips(pancake_list)
    
def rdln(txtin):
    return txtin.readline().strip()

def file_io():
    file_names = 'problemB'
    with open(''.join([file_names, '.in'])) as txtin:
        with open(''.join([file_names, '.out']), 'w') as txtout:
            case_count = int(rdln(txtin))
            for i in range(case_count):
                string = rdln(txtin)
                answer = make_answer(string)
                
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
