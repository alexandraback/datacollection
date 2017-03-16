# Eric Lee < e@ericdlee.com >
# Google Code Jam 2016
# 
# Usage: python A.py small
# list(next()) # List of chars
# [int(n) for n in next().split()] # List of ints
# If multiline, return a list of strings. Else, return a string.

import os, sys, math, fractions

def solve_case(next):
    
    N = int(next())
    lists = []
    grid = []
    missing = 0
    ref = []
    ret = []
    for _ in range(2*N - 1):
        lists.append([int(n) for n in next().split()])
    for i in range(N):
        m = min(l[i] for l in lists)
        cand_indexes = sorted([j for j in range(len(lists)) if lists[j][i] == m], reverse=True)
        cands = [lists[j] for j in cand_indexes]
        if len(cands) == 1:
            missing = i
            ref = cands[0]
        grid.append(cands)
        for j in cand_indexes:
            del lists[j]
    for i in range(N):
        if i == missing:
            ret.append(ref[i])
        else:
            l1, l2 = grid[i]
            viable = set([l1[missing], l2[missing]])
            if len(viable) == 2:
                viable.remove(ref[i])
            ret.append(list(viable)[0])
    return " ".join([str(x) for x in ret])





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
