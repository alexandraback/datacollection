#!/usr/bin/python
# print repr(st)
# maze = [[['#' for i in range(N+2)] for i in range(M+2)] for i in range(4)]
# (M, N) = map(int, f.readline().split())
# l = f.readline()




def doit():
    d = input()
    p = map(int, raw_input().split())

    best = 10**9
    for eat in range(1,1005):
        takes = eat
        for pi in p:
            if pi % eat == 0:
                takes += pi/eat - 1
            else:
                takes += pi/eat
        if takes < best:
            best = takes
    print best

    

cases = input()
for case in range(1, cases+1):
    print ("Case #" + str(case) + ":"),
    doit()
