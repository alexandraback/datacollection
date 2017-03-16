#! /usr/bin/python
# kmwho
# CodeJam 2016  1A

from __future__ import print_function

def solvecase():
    N = int(input().strip())
    rows = [ map(int,input().strip().split()) for i in range(2*N -1) ]
    freq = {}
    for r in rows:
        for num in r:
            if num in freq:
                freq[num] += 1
            else:
                freq[num] = 1
    oddnums = [ num for num in freq if (freq[num] %2 == 1) ]
    return " ".join( map(str,sorted(oddnums)) )

def solve():
    T  = int(input())
    for t in range(1,T+1):
        res = solvecase()
        print( "Case #" + str(t) + ": " + str(res) )

def main():
    solve()


main()
