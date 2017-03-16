#!/usr/bin/env python3

import sys

def solve(l):
    a,b = l[:-1].split(' ')
    iv=0
    total=0
    for i,c in enumerate(b):
        if i <= total:
            total += int(c)
        else:
            iv += i - total
            total += i-total + int(c)
    return iv

def main():
    sys.stdin.readline()
    for i,l in enumerate(sys.stdin.readlines(),1):
        s = solve(l)
        print("Case #{0}: {1}".format(i, s))

if __name__ == '__main__':
    main()
