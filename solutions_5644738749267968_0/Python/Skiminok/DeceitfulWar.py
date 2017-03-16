#!/usr/bin/env python3

import sys
import os
import shutil
import subprocess
from zipfile import ZipFile

def solve_test(inf, filename):
    with open(filename + ".in", 'w+t') as f:
        N = int(inf.readline())
        naomi = [float(x) for x in inf.readline().split()]
        ken = [float(x) for x in inf.readline().split()]
        f.write("{0}\n".format(N))
        f.write("{0}\n".format(" ".join(str(x) for x in naomi)))
        f.write("{0}\n".format(" ".join(str(x) for x in ken)))

    naomi = list(sorted(naomi))
    ken = list(sorted(ken))
    used = set()
    pointsWar = 0
    for n in naomi[::-1]:
        for k in ken:
            if k > n and k not in used:
                used.add(k)
                break
        else:
            pointsWar += 1
            for k in ken:
                if k not in used:
                    used.add(k)
                    break

    used = set()
    pointsDeceitful = 0
    for k in ken:
        for n in naomi:
            if n > k and n not in used:
                used.add(n)
                pointsDeceitful += 1
                break
        else:
            for n in naomi:
                if n not in used:
                    used.add(n)
                    break
    return "{0} {1}".format(pointsDeceitful, pointsWar)

def dump_result(outf, test, result, filename):
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
