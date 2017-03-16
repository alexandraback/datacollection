# usage:  (py3 a.py < a.in) > a.out

import time, sys, inspect

lineno = lambda: inspect.currentframe().f_back.f_back.f_lineno
print = lambda *a, **k: __builtins__.print(str(lineno())+":", *a, file=sys.stderr, **k)
map = lambda *a: list(__builtins__.map(*a))

#---------------------------------------------

"""
intuitive optimal solution:
    'homogenize' pancakes from top to bottom by flipping equal-sided pancakes. eg
        --+-
        +++-
        ----
        ++++ (and one additional if we have all bottoms)
    so we just count number of changes and add one if final pancake is '-'

"""

def run(data):

    prev = data[0]
    flips = 0

    for c in data:
        if prev == c:
            continue
        prev = c
        flips += 1

    return flips + (data[-1] == '-')

#---------------------------------------------

def read_case():
    return input()

for i in range(int(input())):
    outstr = "Case #"+str(i+1)+": "+str(run(read_case()))
    print(outstr, " @ t =", time.clock())
    __builtins__.print(outstr)



