#!/usr/bin/python
import math

def amount(r,n):
    return 2*n*r+2*n*n-n;
def solve(r,n):
    it = 0;
    step = 0;
    first = 0;
    last = n;
    count = last-first;
    while count > 0:
        it = first;
        step = count/2;
        it+=step;
        if amount(r,it) <= n:
            it+=1;
            first = it;
            count=+(step+1);
        else:
            count=step;
    return first-1;

f = open('test.in')
a = int(f.readline())
i =1;
string = "Case #$: "
while a>0:
    out = str(string.replace("$", str(i)))
    r,n = [int(w) for w in f.readline().split()]
    out += str( solve(r,n))
    print out
    i+=1
    a-=1
