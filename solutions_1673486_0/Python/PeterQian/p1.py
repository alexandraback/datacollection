from util import *
import math
def run():
    #enter right away
    max = 1 + penalty
    err = []
    #error possibility to each bit
    l = 1 << a

    for j in range(l):
        pos = 1.0
        t = int(j)
        for k in range(a):
            if t % 2 == 1:
                #k th character is right
                pos *= p[k]
            else:
                pos *= (1.000000 - p[k])
            t = t >> 1
        err.append(pos)
    #keep typing
    """t = err[0] * float(b - a + 1)
    for j in range(1, l):
        t += err[j] * float(b - a + 1 + penalty)
    if t < max:
        max = t
    print(t)"""
    #back space j
    for j in range(0, a+1):
        s = 0.000000
        mask = (1 << (a - j)) - 1
        for k in range(l):
            temp = k & mask
            if temp == mask:
                s += err[k] * (b - (a - j) + 1 + j)
            else:
                s += err[k] * (b - (a - j) + 1 + j + penalty)
        if s < max:
            max = s
    return float(max)
    
    


f = input()
t = int(f)
for i in range(t):
    f = input()
    ab = f.split()
    a = int(ab[0])
    b = int(ab[1])
    f = input()
    ab = f.split()
    p = []
    penalty = b + 1
    for j in range(a):
        p.append(float(ab[j]))
    result = run()
    print('Case #{0}: %.6f'.format(i+1) % result)
    


