#! /usr/bin/python
# kmwho
# CodeJam 2016  1A

from __future__ import print_function

def solvecase():
    S = input().strip()
    l = len(S)
    word = ""
    for c in S:
        word = max( c+word, word+c)
    return word

def solve():
    T  = int(input())
    for t in range(1,T+1):
        res = solvecase()
        print( "Case #" + str(t) + ": " + str(res) )

def main():
	solve()


main()
