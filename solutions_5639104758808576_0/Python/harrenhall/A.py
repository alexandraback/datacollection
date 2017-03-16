#!/usr/bin/python
# print repr(st)
# maze = [[['#' for i in range(N+2)] for i in range(M+2)] for i in range(4)]
# (M, N) = map(int, f.readline().split())
# l = f.readline()




def doit():
    (smax,people) = raw_input().split()
    smax = int(smax)
    d = 0
    stand = 0
    for i in range(smax+1):
        while stand < i:
            d+=1
            stand+=1
        stand += int(people[i])
    print d
    

cases = input()
for case in range(1, cases+1):
    print ("Case #" + str(case) + ":"),
    doit()
