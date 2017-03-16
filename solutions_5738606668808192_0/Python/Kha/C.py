import sys
import math

f = sys.stdin #open('C-small-practice.in')
def get_int(): return int(f.readline())
def get_ints(): return [int(s) for s in f.readline().split()]

def primes(n):
    res = [False, False] + (n-2) * [True]
    for k in range(2, n):
        if res[k]:
            i = 2
            while k*i < n:
                res[k*i] = False
                i += 1
    return res

def divs(n):
    res = n * [None]
    for k in range(2, n):
        if res[k] is None:
            i = 2
            while k*i < n:
                res[k*i] = k
                i += 1
    return res

def find_div(n):
    for k in range(2, 1000): # int(math.sqrt(n))):
        if n % k == 0:
            return k

n = 16 - 1
#j = 50

divs = divs(2**n)
print('Case #1:')

for i in range(2<<(n-1), 2<<n):
    if i % 2 == 0:
        continue
    bi = format(i, 'b')
    my_divs = []
    for k in range(2, 11):
        n = int(bi, k)
        div = find_div(n) if n > 3 else divs[n]
        if not div:
            break
        my_divs.append(div)
    else:
        print(bi, *my_divs)
