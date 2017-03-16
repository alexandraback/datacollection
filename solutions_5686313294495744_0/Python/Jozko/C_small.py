import sys
import numpy as np
import itertools as it
T = int(sys.stdin.readline())

def good(comb, topics):
    K = set()
    K2 = set()
    for (i, j) in comb:
        K.add(i)
        K2.add(j)
    for A, B in topics:
        if A not in K or B not in K2:
            return False
    return True

for case in range(1, T+1):
    sys.stdout.write("Case #%d: " % case)
    sys.stderr.write("Case #%d: \n" % case)
    N = int(sys.stdin.readline())
    topics = []
    for _ in range(N):
        topics.append(sys.stdin.readline().split())
    if N == 1:
        sys.stdout.write("0\n")
        continue
    found = False
    for r in range(16):
        for comb in it.combinations(topics, r):
            if good(comb, topics):
                sys.stdout.write("%d\n" % (N-r))
                found = True
                break
        if found == True:
            break

    if not found:
        sys.stdout.write("%d\n" % 0)
                

