#!/usr/bin/python


def doit():
    (A,B,K) = raw_input().split()
    A=int(A)
    B=int(B)
    K=int(K)
    su = 0
    
    for a in range(A):
        for b in range(B):
            c = a&b
            if c < K:
                su +=1
    print su
    
    

cases = input()
for case in range(1, cases+1):
    
    print ("Case #" + str(case) + ":"),
    
    doit()
    
        
