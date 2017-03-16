# -*- coding: utf-8 -*-
"""
Created on Sat Apr  9 02:06:32 2016

@author: Eidan Cohen
"""


def update(digits_seen, x):
    for digit in str(x):
        digits_seen[int(digit)] = True

def solve(N):
    if N == 0:
        return "INSOMNIA"
    digits_seen = 10*[False]
    i = 0
    while not all(digits_seen):
        i += 1
        update(digits_seen, i*N)
    return str(i*N)
    
def main():
    T = int(input())
    for i in range(1,T+1):
        N = int(input())
        print("Case #%d: %s" % (i, solve(N)))

if __name__ == '__main__':
    main()
        
        