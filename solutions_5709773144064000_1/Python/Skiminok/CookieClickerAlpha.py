#!/usr/bin/env python3

import sys
import os
import shutil
import subprocess
from zipfile import ZipFile

def solve_test(inf, filename):
    with open(filename + ".in", 'w+t') as f:
        C, F, X = [float(x) for x in inf.readline().split()]
        f.write('{0}\n'.format(' '.join(map(str, (C, F, X)))))
    if C > X:
        return X / 2

    score = C
    speed = 2
    elapsed = C / 2
    while score < X:
        time_to_target = (X - score) / speed
        time_with_farm = (X - (score - C)) / (speed + F) 
        if time_to_target < time_with_farm:
            score = X
            elapsed += time_to_target
        else:
            score = C
            speed += F
            elapsed += (C - (score - C)) / speed
    return elapsed

def dump_result(outf, test, result, filename):
    result = "{0:.8f}".format(result)
    with open(filename, 'w+t') as f:
        f.write(result)
    outf.write("Case #{0}: {1}\n".format(test, result))
    

problem_name = sys.argv[1]
size = sys.argv[2]
problem = "{0}-{1}".format(problem_name, size)
path = os.path.join(os.getcwd(), problem + "-data")
shutil.rmtree(path, ignore_errors = True)
os.mkdir(path)

with sys.stdin as inf:
    with open("{0}.out.txt".format(problem), 'w+t') as outf:
        test_count = int(inf.readline())
        for test in range(1, test_count + 1):
            result = solve_test(inf, os.path.join(path, "{0}.{1}".format(problem, test)))
            dump_result(outf, test, result, os.path.join(path, "{0}.{1}.out".format(problem, test)))

with ZipFile("{0}.zip".format(problem), 'w') as zipf:
    zipf.write(os.path.basename(__file__))
