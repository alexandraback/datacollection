#!/bin/python3

t = int(input())
for i in range(t):
    s = set()
    n = int(input())
    nn =n
    if n == 0:
        print("Case #{}: INSOMNIA".format(i+1))
        continue
    while(len(s) < 10):
        s.update({int(a) for a in str(n)})
        n+=nn
    print("Case #{}: {}".format(i+1, n-nn))
