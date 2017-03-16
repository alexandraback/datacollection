# usage:  (py3 a.py < a.in) > a.out

import time, sys, inspect

lineno = lambda: inspect.currentframe().f_back.f_back.f_lineno
print = lambda *a, **k: __builtins__.print(str(lineno())+":", *a, file=sys.stderr, **k)
map = lambda *a: list(__builtins__.map(*a))

#---------------------------------------------

"""
call this script interactively
    python3 -i c.py > c.out
    >>> precompute(6,8)
    >>> main()
"""

d = {}

def precompute(n, j):
    coin = 2**(n-1) + 1

    while j != 0:

        coinstr = bin(coin)[2:]
        certs = [0] * 9

        for base in range(2, 11):

            n = int(coinstr, base)

            # for f in range(2, int(n**.5)+1):
            for f in range(2, min(100, int(n**.5)+1)):
                if n % f == 0:
                    certs[base-2] = str(f)
                    break
            else:
                break

        if all([x != 0 for x in certs]):
            print(coinstr, certs)
            d[coinstr] = certs
            j -= 1

        # guaranteed by problem to be a candidate => coin will never be a digit too long
        coin += 2

def run():
    ret = '\n'
    for coinstr in d:
        ret += coinstr + ' ' + ' '.join(d[coinstr]) + '\n'
    return ret

#---------------------------------------------

def main():
    outstr = "Case #1: "+str(run())
    print(outstr, " @ t =", time.clock())
    __builtins__.print(outstr, end='')



