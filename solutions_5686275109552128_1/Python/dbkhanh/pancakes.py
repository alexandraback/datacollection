#!/usr/bin/env python

import os, sys, math, random

cache = {}

def one_diner(pancakes, max_specials):
    global cache
    if (pancakes, max_specials) in cache:
        return cache[(pancakes, max_specials)]
    best = (pancakes, 0)
    for specials in xrange(1, max_specials+1):
        minutes = specials + int(math.ceil(pancakes/(specials+1.0)))
        if minutes > best[0]: break
        best = min(best, (minutes, specials))
    cache[(pancakes, max_specials)] = best
    return best

def solve(pancakes):
    D = len(pancakes)
    specials = [0 for p in pancakes] # number of special minutes allocated
    heights = [p for p in pancakes] # final max height after all splits
    best = sum(specials) + max(heights) # total breakfast time
    while True:
        # get all ties for tallest final max height
        max_height = max(heights)
        height_cutoff = max_height - 1
        while height_cutoff >= 0:
            bottleneckers = [d for d in xrange(D) if heights[d] > height_cutoff]
            if len(bottleneckers) > max_height - height_cutoff:
                height_cutoff = max_height - len(bottleneckers)
            else:
                break
        # allocate 1 more special minute to each one and see how we do
        new_specials = [s for s in specials]
        new_heights = [h for h in heights]
        for d in bottleneckers:
            new_specials[d] += 1
            new_heights[d] = int(math.ceil(pancakes[d] / (new_specials[d] + 1.0)))
        new_best = sum(new_specials) + max(new_heights)
        if new_best > best:
            # best was already global best
            break
        else:
            specials, heights, best = new_specials, new_heights, new_best
            # in case of tie, keep going since it can take >1 special allocation
            # round to realize an improvement
    return best

def score(pancakes, specials):
    return (max(int(math.ceil(p / (s+1.0))) for p, s in zip(pancakes, specials))
            + sum(specials))

def next(specials, max_specials):
    ret = [s for s in specials]
    if specials == max_specials: return None
    for i in xrange(len(specials)):
        if specials[i] < max_specials[i]:
            ret[i] += 1
            break
        else:
            ret[i] = 0
    return ret

def brute_force(pancakes):
    max_specials = [one_diner(p, p)[1] for p in pancakes]
    specials = [0 for p in pancakes]
    best = max(pancakes)
    while True:
        specials = next(specials, max_specials)
        if specials is None: break
        best = min(best, score(pancakes, specials))
    return best

def main():
    lines = open(sys.argv[1]).read().rstrip().splitlines()
    N = int(lines[0])
    for case in range(1, N+1):
        pancakes = [int(p) for p in lines[2*case].split()]
        answer = solve(pancakes)
        # answer = brute_force(pancakes)
        print("Case #{}: {}".format(case, answer))
        # if answer != brute:
        #     print("Case #{}: {} : {} != {}".format(case, pancakes, answer, brute))

def gen_big():
    print(100)
    for i in xrange(100):
        D = random.randint(1, 1000)
        P = [random.randint(1, 1000) for _ in xrange(D)]
        print(D)
        print(" ".join(str(p) for p in P))

if __name__ == "__main__":
    # gen_big()
    main()
