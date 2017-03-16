#!/usr/bin/python3.2
#name = 'a.test'
#name = 'A-small-attempt0.in'
name = 'A-large.in'

def subMake(A,s,numAdds):
    for i in range(0, numAdds):
        A += (A-1)
        while (len(s) > 0) and s[-1] < A:
            A += s.pop()
    return len(s)


def make():
    A, N = [int(i) for i in FILE.readline().split()]
    sizes = sorted([int(i) for i in FILE.readline().split()], reverse=True)

    while len(sizes) > 0 and sizes[-1] < A:
        A += sizes.pop()
    if len(sizes) == 0: return 0
    if A == 1: return len(sizes)
    worst = len(sizes)
    best = len(sizes)


    for numDuplications in range(1,worst):
        cSize = [i for i in sizes]
        temp = numDuplications + subMake(A, cSize, numDuplications)
        if temp < best:
            best = temp




    return best













FILE = open(name)
T = int(FILE.readline())

for i in range(1, T+1):
    print("Case #" + str(i) + ": " + str(make()))