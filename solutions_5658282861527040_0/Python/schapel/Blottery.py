#!/usr/bin/python3

from sys import argv

def answer(a, b, k):
    count = 0
    for i in range(a):
        for j in range(b):
            if i & j < k:
                count += 1
    return count

if __name__ == '__main__':
    import doctest
    doctest.testmod()

    # Google Code Jam I/O
    infile = open(argv[1])
    cases = int(infile.readline())
    for i in range(cases):
        (a,b,k) = map(int, infile.readline().split())
        print("Case #{}: {}".format(i+1, answer(a, b, k)))
