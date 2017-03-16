#!/usr/bin/env python

import sys
import logging


import itertools


def create_all_decks(N, M):
    nums = range(2, M+1)
    result = itertools.product(*([nums] * N))
    return list(result)


def create_all_products(deck):
    result = [1]
    for d in deck:
        tmp = [d * x for x in result]
        result = result + tmp
    return result


def create_probs(products):
    probs = {}
    N = len(products)
    q = 1.0/N
    for p in products:
        if p in probs:
            probs[p] += q
        else:
            probs[p] = q
    return probs

def max_likelihood(values, observations):
    best = None
    best_l = 0
    
    for (x, probs) in values:
        p = 1
        for k in observations:
            if k not in probs:
                p = 0
                break
            p *= probs[k]
        if p > best_l:
            best_l = p
            best = x
    print best_l
    return best


        
def make_big(N, M):
    results = []
    def f(cur, i):
        if len(cur) == N:
            results.append(cur)
        elif i > M:
            pass

        else:
            f(cur, i + 1)
            while True:
                cur = cur + [i]
                f(cur, i + 1)
                if len(cur) == N:
                    break
    f([], 2)
    return results

    
def solve(obs, values):
    return max_likelihood(values, obs)

def main(lines, output):
    T = int(lines.next())
    R, N, M, K = [int(x) for x in lines.next().split()]
    values = [(x, create_probs(create_all_products(x)))
              for x in make_big(N, M)]

    output.write("Case #1:\n")
    
    for obs in xrange(1,R+1):
        vals = [int(x) for x in lines.next().split()]
        guess = solve(vals, values)
        s = "".join(["%d" % d for d in guess])
        output.write(s + "\n")
        logging.info(s)
    


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print "expects filename"
        sys.exit(1)
    logging.basicConfig(level=logging.DEBUG)
    outfile = sys.argv[1] + ".out"
    main(open(sys.argv[1]), open(outfile, "w"))

