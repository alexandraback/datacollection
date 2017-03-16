#!/usr/bin/python
# print repr(st)
# maze = [[['#' for i in range(N+2)] for i in range(M+2)] for i in range(4)]
# (M, N) = map(int, f.readline().split())
# l = f.readline()


pa = "RICHARD"
pb = "GABRIEL"


def doit():
    (x,r,c) = map(int, raw_input().split())
    if r < c:
        (r,c) = (c,r)
    
    if x == 1:
        return pb
    
    if (r*c) % x != 0:
        return pa
        
    if x > r:
        return pa
        
    if x == 2:
        return pb
        
    if x == 3:
        if c == 1:
            return pa
        return pb
        
    if x == 4:
        if c == 1:
            return pa
        if c == 2:
            return pa
        return pb
    
    
    

cases = input()
for case in range(1, cases+1):
    print ("Case #" + str(case) + ":"), doit()
