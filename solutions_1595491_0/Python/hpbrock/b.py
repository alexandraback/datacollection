# coding: utf8
import math

def scan():
    while True:
        for w in raw_input().split():
            yield w

words = scan()

def scans(num=-1):
    return (next(words) for i in xrange(num)) if num >= 0 else next(words)

def scani(num=-1):
    return (int(value) for value in scans(num)) if num >= 0 else int(scans())

#------------------------------------------------------------------------------
for case in xrange(1, scani() + 1):
    print "Case #%d:" % (case,),
    n, s, p = scani(3)
    min_count, max_count = (0, 0)
    for score in scani(n):
        if score == 0:
            min_count += 1 if p == 0 else 0
            max_count += 1 if p == 0 else 0
        else:
            min_count += 1 if (score / 3.0) + 0.75 >= p else 0
            max_count += 1 if (score / 3.0) + 1.50 >= p else 0
    print min(min_count + s, max_count)
