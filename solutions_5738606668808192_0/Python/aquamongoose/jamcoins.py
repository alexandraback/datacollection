import random
import math

N = 16
J = 50

def print_coin(c):
    print(c, end=' ')
    for i in range(2, 11):
        print(i+1, end=' ')
    print()

def good(c):
    s = 0
    t = 1
    for cc in c:
        s += int(cc)*t
        t *= -1
    return s == 0

def rando_coin():
    return '1' + ''.join(random.choice(['0', '1']) for _ in range(N-2)) + '1'

print('Case #1:')
used = set()
for i in range(J):
    c = rando_coin()
    while c in used or not good(c):
        c = rando_coin()
    used.add(c)
    print_coin(c)
