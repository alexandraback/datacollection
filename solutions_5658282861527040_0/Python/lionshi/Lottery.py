#!/usr/bin/python3
# -*- coding: utf-8 -*-

def main():
    in_file = open("B-small-attempt0.in", mode='r')
    out_file = open("B-small-attempt0.out", mode='w')

    MAX = 10

    T = int(in_file.readline())
    
    for i in range(T):
        A, B, K = [int(s) for s in in_file.readline().split()]

        result = 0
        for a in range(A):
            for b in range(B):
                if (a & b) < K:
                    result += 1

        out_file.write("Case #" + str(i+1) + ": " + str(result) + "\n") 

    in_file.close()
    out_file.close()

    
if __name__ == '__main__':
    main()