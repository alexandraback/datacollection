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

global_st = {}

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
        global_st["case"] = i + 1
        c = parse_case(inp)
        print "Solving case #%d (%s)" % (i + 1, c)
        solution = solve(c)
        print >> out, "Case #%d: %s" % (i + 1, solution)

from itertools import imap, groupby, repeat, combinations_with_replacement, product
from functools import reduce
import operator

def parse_case(inp):
    k, l, s = map(int, inp.next().split())
    keyboard = inp.next().strip()
    target = inp.next().strip()

    assert len(keyboard) == k
    assert len(target) == l

    return (s, keyboard, target)


def occurences(text, word):
    occs = len([i for i, _ in enumerate(text) if text.startswith(word, i)])
    return occs


def solve(( s, keyboard, target)):
    assert s <= 7

    cs = list(product(keyboard, repeat=s))
    occs = list(occurences("".join(x), target) for x in cs)

    max_occs = max(occs)

    avg_occs = float(sum(occs)) / len(occs)

    if max_occs == 0:
        return 0

    if global_st["case"] == -1:
        print max_occs, avg_occs
        for x in zip(occs, cs):
            print x
        print len(occs)

    return max_occs - avg_occs

if __name__ == "__main__":
    main()
