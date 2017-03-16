#!/usr/bin/python
# print repr(st)
# maze = [[['#' for i in range(N+2)] for i in range(M+2)] for i in range(4)]
# (M, N) = map(int, f.readline().split())
# l = f.readline()
import math

def stellen(n):
    st = 0
    while n>0:
        st+=1
        n/=10
    return st
    
def flip(st):
    return st[::-1]

def doit():
    n = input()
    if n < 13:
        return n
    said = 10
    rea = 10
    
    while stellen(rea) < stellen(n):
        st = stellen(rea)
        n1 = int(math.floor(st/2.0))
        n2 = int(math.ceil(st/2.0))
        #print n1,n2
        said += int("9"*n1)
        said += 1
        said += int("9"*n2)
        rea *= 10
        #print said
    
    if rea == n:
        return said
    
    st = stellen(n)
    n1 = int(math.floor(st/2.0))
    n2 = int(math.ceil(st/2.0))
    
    nn = str(n)
    nn1 = nn[:n1]
    nn2 = nn[n1:]
    
    if nn1 == "1" + "0"*(n1-1):
        #print 'lala'
        return said + int(nn2)
    
    
    nn2 = int(nn2)
    
    if nn2 == 0:
        nn1 = int(nn1)
        nn1 -=1
        nn1 = str(nn1)
        
    nn1 = flip(nn1)
    nn1 = int(nn1)
    
    #print said, nn1, nn2
    
    said += nn1
    if nn1 > 1:
        said +=1
    if nn2 == 0:
        nn2 = int("1" + "0"*(n2))
        
    said += nn2 - 1
    return said    
    
    

cases = input()
for case in range(1, cases+1):
    print ("Case #" + str(case) + ":"), doit()
