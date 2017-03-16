import sys
import re

class Teed(object):
    """Wraps a file object. It behaves mostly like the original one,
     but the calls to "write" are replicated to stdout.

     The writelines method is not overriden yet.
     """

    def __init__(self, original):
        self._orig = original

    def write(self, str):
        sys.stdout.write(str)
        self._orig.write(str)

    def __getattr__(self, property):
        """Delagate all other properties
           and method calls to wrapped object"""
        return self._orig.__getattribute__(property)

def main():
    name = re.match(r"^(.*\.)in$", sys.argv[1]).group(1) + "out"

    with open(sys.argv[1]) as f:
        orig_out = sys.stdout
        with open(name, "w") as out_f:
            wrapped = Teed(out_f)
            parse(f, wrapped)

def parse(inp, out):
    cases = int(inp.next().strip())
    for i in range(cases):
        c = parse_case(inp)
        print "Solving case #%d (%s)" % (i + 1, c)
        solution = solve(c)
        print >> out, "Case #%d: %s" % (i + 1, solution)

from itertools import imap, groupby, repeat
from functools import reduce
import operator
import numpy as np

def parse_case(inp):
    return map(int, inp.next().split())


def solve((r, c, w)):
    misses = c / w
    left_sq = c % w

    if left_sq == 0:
        misses -= 1

    return (r - 1) * (c / w) + (misses + w)

if __name__ == "__main__":
    main()
