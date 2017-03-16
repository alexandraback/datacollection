import numpy as np
import itertools
from collections import defaultdict

def solveCaseArr(nums):
    d = defaultdict(lambda: [])
    for L in xrange(2, len(nums)/2 + 1):
        for subset in itertools.combinations(nums, L):
            subset = list(subset)
            subset_set = set(subset)
            S = sum(subset)
            if S in d:
                for a in d[S]:
                    if a.isdisjoint(subset_set):
                        return list(a), subset
            else:
                d[S].append(subset_set)
    return [], []

def solveCase(nums):
    a,b = solveCaseArr(nums)
    if len(a) == 0:
        return "\r\nImpossible"
    astr = " ".join([str(i) for i in a])
    bstr = " ".join([str(i) for i in b])
    return "\r\n%s\r\n%s" % (astr, bstr)

def parseSolveCase(s):
    l = parseCase(s)
    return solveCase(l[1:])

def parseCase(s):
    return [int(i) for i in s.split(" ")]

def solve(fil):
    fout = open("out.txt", mode = "wb")
    lNum = 0
    with open(fil) as f:
        for line in f:
            if lNum > 0:
                fout.write("Case #%d:%s\r\n" \
                           % (lNum, parseSolveCase(line)))
            lNum += 1
    fout.close()
