__author__ = 'lowikchanussot'

from collections import defaultdict

def isPossible(target, keyboard) :
    t = set(target)
    k = set(keyboard)
    return t.issubset(k)

def getOverlapping(target) :
    for i in reversed(range(1, len(target))) :
        if target.endswith(target[:i]) :
            return i
    return 0

def getMaxOccur(target, S) :
    overlap = getOverlapping(target)
    T = len(target) - overlap
    L = len(target)
    return max(0, (S-L)/T + 1)

def buildProbaDict(keyboard) :
    proba = defaultdict(int)
    for k in keyboard :
        proba[k] += 1
    proba = {key: values/(len(keyboard) * 1.0) for key, values in proba.iteritems()}
    return proba

def survivalProbability(target, keyboard) :
    proba = buildProbaDict(keyboard)
    s = 1.0
    for t in target :
        s *= proba[t]
    return s

def get_expected_bananas(target, keyboard, S) :
    s = survivalProbability(target, keyboard)
    return (S - len(target) + 1) * s

def solveB(target, keyboard, S) :
    if not isPossible(target, keyboard) : return 0.0
    max_bananas = getMaxOccur(target, S)
    expected_bananas = get_expected_bananas(target, keyboard, S)
    return max_bananas - expected_bananas

def solve(in_filename, out_filename):
    with open(in_filename, 'r') as file, open(out_filename, 'w') as ofile :
        lines = file.readlines()
        T = int(lines[0].strip())

        for case in range(0, T) :
            tokens = lines[3*case + 1].split()
            K, L, S = int(tokens[0]), int(tokens[1]), int(tokens[2])
            keyboard = lines[3*case+2].strip()
            target = lines[3*case+3].strip()
            sol = solveB(target, keyboard, S)
            ofile.write("Case #%d: %12.12f\n"%(case+1, sol))

if __name__ == '__main__':
    import sys
    import os
    _, input = sys.argv
    output = os.path.splitext(input)[0] + '.out'
    solve(input, output)