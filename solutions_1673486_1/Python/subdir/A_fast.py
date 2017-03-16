#!/usr/bin/python

import sys

def hit_enter(B):
    return B + 2

def finish_typing(A, B, corhead):
    return corhead[-1] * (B - A + 1) + (1 - corhead[-1]) * (B - A + 1 + B + 1)

def hit_backspace(n, A, B, corhead):
    t = n + (B - (A - n)) + 1
    return corhead[A - n] * t + (1 - corhead[A - n]) * (t + B + 1)

def case(A, B, probs):
    corhead = [1.0]
    for l in xrange(1, len(probs) + 1):
        v = 1.0
        for i in xrange(l):
            v *= probs[i]
        corhead.append(v)

    """
    print "corhea", corhead
    print "enter ", hit_enter()
    print "finish", finish_typing()
    for n in xrange(1, len(corhead) + 1):
        print "back ", n, hit_backspace(n)
    """

    min_strokes = min(hit_enter(B), finish_typing(A, B, corhead))
    for n in xrange(1, len(corhead) + 1):
        min_strokes = min(min_strokes, hit_backspace(n, A, B, corhead))

    return min_strokes

def main():
    T = int(sys.stdin.readline())
    for x in xrange(1, T+1):
        A, B = map(int, sys.stdin.readline().split())
        probs = [float(p) for p in sys.stdin.readline().split()]
        assert len(probs) == A
        print "Case #%d: %0.8f" % (x, case(A, B, probs))

main()
