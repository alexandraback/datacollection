"""
Google Code Jam 2016 Qualification Round Problem A

Author  : chaotic_iak
Language: Python 3.4.3
"""

################################################### SOLUTION

def initialize():
    pass

def find(n):
    ct = 0
    target = set(map(str, range(10)))
    while target:
        ct += n
        target = target.difference(set(str(ct)))
    return ct

def solve():
    n = read()[0]
    if n == 0:
        write("INSOMNIA")
    else:
        write(find(n))

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
        solve()
        write("\n")

if tfile: tfile.close()
