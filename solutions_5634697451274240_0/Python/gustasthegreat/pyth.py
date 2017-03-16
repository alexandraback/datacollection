#!/bin/python3

t = int(input())
for tcase in range(t):
    s =  input()
    s=s.rstrip('+')
    for i in range(len(s)//2+2):
        s=s.replace('++', '+')
        s=s.replace('--', '-')
    print("Case #{}: {}".format(tcase+1, len(s)))
