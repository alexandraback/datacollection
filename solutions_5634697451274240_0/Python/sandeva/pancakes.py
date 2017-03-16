import sys
import re


def f(S):
    s = re.sub(r'\+$', '', re.sub(r'([-+])\1+', r'\1', S.strip()))
    return len(s)

with open(sys.argv[1]) as fi:
    for i, n in enumerate(fi.readlines()[1:]):
        print "Case #%d:" % (i + 1), f(n)
