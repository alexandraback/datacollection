"""
Google Code Jam 2016 Round 1B Problem A

Author  : chaotic_iak
Language: Python 3.4.3
"""

################################################### SOLUTION

def initialize():
    pass

def subtract(arr, name, count):
    for c in name:
        arr[ord(c)-64] -= count

def solve():
    s = read(0)
    arr = [0] * 27
    for c in s:
        arr[ord(c)-64] += 1
    counts = [0] * 10

    counts[0] = arr[26]
    subtract(arr, "ZERO", counts[0])
    counts[2] = arr[23]
    subtract(arr, "TWO", counts[2])
    counts[6] = arr[24]
    subtract(arr, "SIX", counts[6])
    counts[7] = arr[19]
    subtract(arr, "SEVEN", counts[7])
    counts[5] = arr[22]
    subtract(arr, "FIVE", counts[5])
    counts[4] = arr[6]
    subtract(arr, "FOUR", counts[4])
    counts[3] = arr[18]
    subtract(arr, "THREE", counts[3])
    counts[8] = arr[7]
    subtract(arr, "EIGHT", counts[8])
    counts[9] = arr[9]
    subtract(arr, "NINE", counts[9])
    counts[1] = arr[15]
    subtract(arr, "ONE", counts[1])
    write("".join(str(i) * counts[i] for i in range(10)))

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
if tfile is not None: tfile.close()
