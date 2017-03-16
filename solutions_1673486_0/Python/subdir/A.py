#!/usr/bin/python

import sys
from operator import mul
from itertools import islice

def case(A, B, probs):
    corhead = [1.0]
    for l in xrange(1, len(probs) + 1):
        corhead.append(reduce(mul, islice(probs, l), 1.0))

    def hit_enter():
        return B + 2

    def finish_typing():
        return corhead[-1] * (B - A + 1) + (1 - corhead[-1]) * (B - A + 1 + B + 1)

    def hit_backspace(n):
        t = n + (B - (A - n)) + 1
        return corhead[A - n] * t + (1 - corhead[A - n]) * (t + B + 1)

    """
    print "corhea", corhead
    print "enter ", hit_enter()
    print "finish", finish_typing()
    for n in xrange(1, len(corhead) + 1):
        print "back ", n, hit_backspace(n)
    """

    min_strokes = min(hit_enter(), finish_typing())
    for n in xrange(1, len(corhead) + 1):
        min_strokes = min(min_strokes, hit_backspace(n))
    return min_strokes

def main():
    T = int(next(sys.stdin))
    for x in xrange(1, T+1):
        A, B = map(int, next(sys.stdin).split())
        probs = [float(p) for p in next(sys.stdin).split()]
        assert len(probs) == A
        print "Case #%d: %0.8f" % (x, case(A, B, probs))

main()
