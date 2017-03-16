# -*- coding: utf-8 -*-
"""
Created on Sat Apr  9 02:19:29 2016

@author: Eidan Cohen
"""


def rec_solve(uniq):
    if len(uniq) == 1:
        if uniq == '+':
            return 0
        if uniq == '-':
            return 1
    return 1 + rec_solve(uniq[1:])

def solve(stack):
    current = None
    uniq = ""
    for p in stack:
        if p != current:
            uniq += p
            current = p
    return rec_solve(uniq)
        
def main():
    T = int(input())
    for i in range(1,T+1):
        stack = input().strip()
        print("Case #%d: %d" % (i, solve(stack)))

if __name__ == '__main__':
    main()
        
        