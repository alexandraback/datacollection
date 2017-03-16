import sys
from collections import defaultdict
from itertools import permutations
import random

def outfits(J, P, S):
    for j in range(1, J + 1):
        for p in range(1, P + 1):
            for s in range(1, S + 1):
                yield j, p, s


def fp(J, P, S, K, order):
    total = 0
    jp = defaultdict(int)
    js = defaultdict(int)
    ps = defaultdict(int)
    sols = []

    for j, p, s in order:
        if jp[(j, p)] < K and js[(j, s)] < K and ps[(p, s)] < K:
            jp[(j, p)] += 1
            js[(j, s)] += 1
            ps[(p, s)] += 1
            sols += [(j, p, s)]
            total += 1
    return total, sols


def output_rand(J, P, S, K):
    total = 0
    jp = defaultdict(int)
    js = defaultdict(int)
    ps = defaultdict(int)
    sols = []
    seen = set()

    while True:
        best_reps = 4 * K
        best = []
        for j, p, s in outfits(J, P, S):
            if (j, p, s) in seen:
                continue
            reps = jp[(j, p)], js[(j, s)], ps[(p, s)]
            if max(reps) < K:
                best += [(j, p, s)]
                # best_reps = tot_reps
        if not best:
            break
        # print(best, best_reps)
        j, p, s = random.choice(best)
        jp[(j, p)] += 1
        js[(j, s)] += 1
        ps[(p, s)] += 1
        sols += [(j, p, s)]
        total += 1
        seen.add((j, p, s))
    return total, sols

def output(J, P, S, K):
    best = 0
    for i in range(100):
        total, sols = output_rand(J, P, S, K)
        if total > best:
            best = total
            best_sols = sols
    return best, best_sols

if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in range(T):
        J, P, S, K = map(int, sys.stdin.readline().strip().split(" "))
        answer, sols = output(J, P, S, K)
        print("Case #%d: %s" % (t + 1, answer))
        for sol in sols:
            print(" ".join(map(str, sol)))
