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

def parse_case(inp):
    n = int(inp.next())
    groups = []
    for i in range(n):
        groups.append(map(int, inp.next().split()))
    return groups

def solve(groups):
    hikers = []
    for start, n, m in groups:
        for i in range(n):
            hikers.append((start, m + i))

    by_speed = [(s, sorted([x[0] for x in h])) for s, h in groupby(sorted(hikers, key=lambda x:x[1]), key=lambda x: x[1])]
    print by_speed

    if len(by_speed) < 2:
        return 0

    assert len(by_speed) == 2, by_speed

    a = by_speed[0][0], by_speed[0][1][0]
    b = by_speed[1][0], by_speed[1][1][0]

    print a, "faster"
    print b, "slower"
    b_t = b[0] * (360 - b[1])
    a_2t = a[0] * ((360 + a[1] - b[1]) % 360)

    print b_t, a_2t

    if a_2t < b_t:
        return 1
    else:
        return 0

if __name__ == "__main__":
    main()
