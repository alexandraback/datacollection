"""Solve the 'Counter Culture' problem."""

from solver import solver
from math import log

def c1(n):
    s = len(str(n))
    m = int(str(n)[:s/2] + "0" * ((s+1)/2-1) + "1")
    c = n - m + 1
    n = int(str(m)[::-1])
    return c + c2(n)

def c2(n):
    return int(str(n)[1:]) if str(n).startswith("1") else n

    
def red(n):
    if n < 21:
        return n
    if not n%10:
        return 1 + red(n-1)
    c = min(c1(n), c2(n))    
    return c + red(10 ** (len(str(n))-1))


@solver
def counter(lines):
    arg = int(lines[0])
    return red(arg)

if __name__ == "__main__":
    counter.from_cli()
