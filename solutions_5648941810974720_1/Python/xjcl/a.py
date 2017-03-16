# usage:  (py3 a.py < a.in) > a.out

import time, sys, inspect

lineno = lambda: inspect.currentframe().f_back.f_back.f_lineno
print = lambda *a, **k: __builtins__.print(str(lineno())+':', *a, file=sys.stderr, **k)
map = lambda *a: list(__builtins__.map(*a))
reversed = lambda *a: list(__builtins__.reversed(*a))

#---------------------------------------------

'''

Z -> ZERO
W -> TWO
U -> FOUR
X -> SIX
----
F -> FIVE (after rm 4)
R -> THREE (after rm 0,4)
O -> ONE (after rm 0,2,4)
S -> SEVEN (after rm 6)
T -> EIGHT (after rm 2,3)
I -> NINE (after rm 5,6,8)

"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"

then just sort (since monotonically increasing)

'''

from collections import *

def count_and_rm(d, c, k, indic, rmlist):

    how_many_ks = c[indic]
    d[k] = how_many_ks

    for r in rmlist:
        c[r] -= how_many_ks


def run(data):

    counts = Counter(data)
    # print(counts)

    num = dict()

    count_and_rm(num, counts, 0, 'Z', 'ZERO')
    count_and_rm(num, counts, 2, 'W', 'TWO')
    count_and_rm(num, counts, 4, 'U', 'FOUR')
    count_and_rm(num, counts, 6, 'X', 'SIX')
    count_and_rm(num, counts, 5, 'F', 'FIVE')
    count_and_rm(num, counts, 3, 'R', 'THREE')
    count_and_rm(num, counts, 1, 'O', 'ONE')
    count_and_rm(num, counts, 7, 'S', 'SEVEN')
    count_and_rm(num, counts, 8, 'T', 'EIGHT')
    count_and_rm(num, counts, 9, 'I', 'NINE')

    ret = []
    for i in range(10):
        ret += [str(i)] * num[i]

    return ''.join(ret)

#---------------------------------------------

def read_case():
    return input()
    #return [[int(n) for n in input().split()] for i in range(4)]

for i in range(int(input())):
    outstr = 'Case #'+str(i+1)+': '+str(run(read_case()))
    print(outstr, ' @ t =', time.clock())
    __builtins__.print(outstr)


