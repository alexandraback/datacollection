"""
Google Code Jam 2015 Qualification Round Problem C

Author  : chaotic_iak
Language: Python 3.4.2
"""

################################################### SOLUTION

mult_table = {
    1: {1: 1, 2:  2, 3:  3, 4:  4},
    2: {1: 2, 2: -1, 3:  4, 4: -3},
    3: {1: 3, 2: -4, 3: -1, 4:  2},
    4: {1: 4, 2:  3, 3: -2, 4: -1}
}

def mul(a, b):
    sign = 1
    if a < 0:
        a = -a
        sign *= -1
    if b < 0:
        b = -b
        sign *= -1
    return mult_table[a][b] * sign

def initialize():
    pass

def solve():
    l, x = read()
    s = read(0)
    if x >= 12: x = (x-12) % 4 + 12
    s = s * x
    data = [ord(i)-103 for i in s]      # ord("g") = 103
    curr = 1
    step = 0
    for i in data:
        curr = mul(curr, i)
        if step == 0 and curr == 2: step = 1
        if step == 1 and curr == 4: step = 2
    if step == 2 and curr == -1:
        write("YES")
    else:
        write("NO")

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
