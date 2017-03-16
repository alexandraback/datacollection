# Eric Lee < e@ericdlee.com >
# Google Code Jam 2016
# 
# Usage: python A.py small
# list(next()) # List of chars
# [int(n) for n in next().split()] # List of ints
# If multiline, return a list of strings. Else, return a string.

import os, sys, math, fractions
from collections import Counter

def solve_case(next):
    
    N = int(next())
    bff = [int(n) - 1 for n in next().split()]
    best_closed = 0
    cores = []
    chains = {}
    for i in range(N):
        j = i
        visited = set()
        l = []
        while j not in visited:
            visited.add(j)
            l.append(j)
            j = bff[j]
        if len(l) == 2:
            cores.append(tuple(l))
        elif j == l[0]:
            best_closed = max(best_closed, len(l))
        elif j == l[-2]:
            core = tuple(l[-2:])
            if core in chains:
                chains[core] = max(chains[core], len(l) - 2)
            else:
                chains[core] = len(l) - 2
    best_augmented = 0
    for core in cores:
        if core in chains:
            best_augmented += 1 + chains[core]
        else:
            best_augmented += 1
    return max(best_closed, best_augmented)






# ---------------------------------------------------------------------------- #

def solve(next, emit):
    cases = int(next())
    for case in range(1, cases + 1):
        sol = solve_case(next)
        if isinstance(sol, list):
            emit("Case #{0}:".format(case))
            for line in sol:
                emit(str(line))
        else:
            emit("Case #{0}: {1}".format(case, str(sol)))
        print("{0} / {1}".format(case, cases))

if __name__ == "__main__":
    if len(sys.argv) == 1:
        print("Usage: python {0} small".format(sys.argv[0]))
        exit()
    prefix = sys.argv[0][:-3] + "-" + sys.argv[1]
    suffix = ".in"
    for file in os.listdir(os.path.dirname(os.path.realpath(__file__))):
        if file.startswith(prefix) and file.endswith(suffix):
            print("Loading " + file)
            file_in = open(file, "r")
            file_out = open(file[:-3] + ".out", "w")
            solve(lambda: file_in.readline().strip(), lambda x: file_out.write(str(x) + "\n"))
            file_in.close()
            file_out.close()
            print("Complete.")
