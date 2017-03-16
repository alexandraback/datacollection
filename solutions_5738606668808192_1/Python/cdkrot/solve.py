#!/usr/bin/python3

import sys

def expect(res, msg="FAIL"):
    if not res:
        print(msg)
        sys.exit(1)

def gen_seqs(length):
    if length == 0:
        return [""]
    else:
        base = gen_seqs(length - 1)
        res = []
        for elem in base:
            res.append(elem + "00")
            res.append(elem + "11")
        return res
        
def main():
    int(input())
    N, J = map(int, input().split())
    expect(N >= 2)
    expect(N % 2 == 0)
    
    seqs = gen_seqs((N - 4) / 2)
    expect(len(seqs) >= J)
    
    print("Case #1:")
    for i in range(J):
        print("11" + seqs[i] + "11 3 4 5 6 7 8 9 10 11")

main()
