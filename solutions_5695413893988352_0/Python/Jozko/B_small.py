import sys
from collections import defaultdict
import numpy as np
T = int(sys.stdin.readline())

def replace(c, j, v):
    a, b = str(v[0]), str(v[1])
    a = '0'*(len(c)-len(a)) + a
    b = '0'*(len(c)-len(b)) + b
    return a, b


def match(c,j, C, J):
    C, J = str(C), str(J)
    
    c = '0'*(3-len(c)) + c
    C = '0'*(3-len(C)) + C 
    j = '0'*(3-len(j)) + j
    J = '0'*(3-len(J)) + J
    for a, b in zip(c,C):
        if a != b and a != '?':
            return False
    for a, b in zip(j,J):
        if a != b and a != '?':
            return False
    return True

for case in range(1, T+1):

    sys.stderr.write("Case #%d: \n" % case)
    sys.stdout.write("Case #%d: " % case)
    c, j = sys.stdin.readline().split()
    counts = defaultdict(list)
    currBest, currList = 9999999, []
    for C in range(0, 1000):
        for J in range(0, 1000):
            if abs(C-J) <= currBest and match(c, j, C, J):
                if abs(C-J) < currBest:
                    currBest = abs(C-J)
                    currList = [(C,J)]
                if abs(C-J) == currBest:
                    currList.append((C,J))

    counts[currBest] = currList
    m = min(counts.keys())
    if len(counts[m]) > 1:
        v = min(counts[m], key=lambda x: x[0])
        N = sum(map(lambda x: 1 if x[0] == v[0] else 0, counts[m]))
        if N == 1:
            v = replace(c, j, v)
            sys.stdout.write("%s %s\n" % (v[0], v[1]))
        else:
            v = min(counts[m], key=lambda x: x[1])
            v = replace(c, j, v)
            sys.stdout.write("%s %s\n" % (v[0], v[1]))
    else:
        v = replace(c, j, counts[m][0])
        sys.stdout.write("%s %s\n" % (v[0], v[1]))
            




