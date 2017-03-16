# usage:  (py3 a.py < a.in) > a.out

import time, sys, inspect

lineno = lambda: inspect.currentframe().f_back.f_back.f_lineno
print = lambda *a, **k: __builtins__.print(str(lineno())+":", *a, file=sys.stderr, **k)
map = lambda *a: list(__builtins__.map(*a))

#---------------------------------------------

"""
do we have to do simulation?
    we can test feasibility of that by pre-computing all 10**6 cases

when does it cycle?
    is 0 only number that cycles?
    can we detect cycling?

yup, simulation stays easily within the time limit and only 0 cycles

reason: 0 will be last digit for 10*n (10*n ends in 0)
    1..9 will be leading digit for k-digit multiples
        where k is the smallest number such that  10**k >= n
    since  10**k + n <= 10**k + 10**k = 2 * 10**k
    eg: for numbers between 10 and 100 we are guaranteed 3-digit
        multiples of the form 1xx, 2xx, 3xx, .., 9xx
        simply because 10..100 are less then 100!

"""

def run(n):

    if n == 0:
        return "INSOMNIA"

    unseen = [str(x) for x in range(10)]
    cur = 0
    while unseen:
        cur += n
        for c in str(cur):
            if c in unseen:
                unseen.remove(c)

    return cur

#---------------------------------------------

def read_case():
    return int(input())

for i in range(int(input())):
    outstr = "Case #"+str(i+1)+": "+str(run(read_case()))
    print(outstr, " @ t =", time.clock())
    __builtins__.print(outstr)



