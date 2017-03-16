"""
Google Code Jam 2016 Round 1B Problem C

Author  : chaotic_iak
Language: Python 3.4.3
"""

################################################### SOLUTION

import itertools

def initialize():
    pass

def solve():
    n, = read()
    words = []
    for i in range(n):
        words.append(read(1))

    for k in range(n+1):
        for combo in itertools.combinations(range(n), k):
            for t in range(n):
                if (all(words[i][0] != words[t][0] for i in combo) or
                    all(words[i][1] != words[t][1] for i in combo)):
                    break
            else:
                return n-k

#################################################### HELPERS

# 0  : Single testcase, solve() only
# str: Multiple testcase, print output_format before
#                         %d replaced with case number
output_format = "Case #%d: "

filename = input().strip()
sfile = None
tfile = None
if filename != "":
    sfile = open(filename + ".in", "r")
    sfile.seek(0)
    tfile = open(filename + ".out", "w")

def read(mode=2):
    # 0: String
    # 1: List of strings
    # 2: List of integers
    if sfile:
        input_line = sfile.readline().strip()
    else:
        input_line = input().strip()
    if mode == 0: return input_line
    if mode == 1: return input_line.split()
    if mode == 2: return list(map(int, input_line.split()))

def write(s="\n"):
    if s is None: s = ""
    if isinstance(s, list): s = " ".join(map(str, s))
    s = str(s)
    if tfile:
        tfile.write(s)
    else:
        print(s, end="")

if output_format == 0:
    solve()
else:
    initialize()
    total_cases = int(read(0))
    for case_number in range(1, total_cases+1):
        write(output_format.replace("%d", str(case_number)))
        write(solve())
        write("\n")
if tfile is not None: tfile.close()
