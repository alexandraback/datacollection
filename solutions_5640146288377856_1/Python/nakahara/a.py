import math

def solve():
    a=input()
    R=int(a.split()[0])
    C=int(a.split()[1])
    W=int(a.split()[2])

    num = (C // W)*R
    if C%W==0:
        num -=1
    return str(num+W)

T=int(input());

for t in range(1,T+1):
    print ("Case #" + str(t) + ": " + solve())