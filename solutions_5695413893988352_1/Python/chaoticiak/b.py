"""
Google Code Jam 2016 Round 1B Problem B

Author  : chaotic_iak
Language: Python 3.4.3
"""

################################################### SOLUTION

def initialize():
    pass

def complete(a, b):
    return ("".join("0" if c == "?" else c for c in a),
            "".join("9" if c == "?" else c for c in b))

def get(a, b):
    if a == b == "": return "", ""
    
    if a[0] != "?" and b[0] != "?":
        if a[0] < b[0]:
            return "FALSE", "FALSE"
        if a[0] == b[0]:
            ar, br = get(a[1:], b[1:])
            if ar == "FALSE":
                return "FALSE", "FALSE"
            return a[0] + ar, b[0] + br
        return complete(a, b)

    candidates = []
    if a[0] == "?" and b[0] != "?":
        candidates.append((b[0] + a[1:], b))
        if b[0] != "9":
            candidates.append((str(int(b[0])+1) + a[1:], b))
        else:
            candidates.append(("0", "1"))
    if a[0] != "?" and b[0] == "?":
        candidates.append((a, a[0] + b[1:]))
        if a[0] != "0":
            candidates.append((a, str(int(a[0])-1) + b[1:]))
        else:
            candidates.append(("0", "1"))
    if a[0] == "?" and b[0] == "?":
        candidates.append(("0" + a[1:], "0" + b[1:]))
        candidates.append(("1" + a[1:], "0" + b[1:]))

    results = [get(*candidates[0]), get(*candidates[1])]
    if results[0][0] == "FALSE" and results[1][0] == "FALSE":
        return "FALSE", "FALSE"
    if results[0][0] == "FALSE":
        return results[1]
    if results[1][0] == "FALSE":
        return results[0]

    diff1 = int(results[0][0]) - int(results[0][1])
    diff2 = int(results[1][0]) - int(results[1][1])
    if diff1 < diff2:
        return results[0]
    if diff1 > diff2:
        return results[1]
    if results[0][0] < results[1][0]:
        return results[0]
    if results[0][0] > results[1][0]:
        return results[1]
    if results[0][1] < results[1][1]:
        return results[0]
    return results[1]

def solve():
    s = read(1)
    results = [get(s[0], s[1]), get(s[1], s[0])]
    if results[0][0] == "FALSE" and results[1][0] == "FALSE":
        return "FALSE", "FALSE"
    if results[0][0] == "FALSE":
        return reversed(results[1])
    if results[1][0] == "FALSE":
        return results[0]
    diff1 = int(results[0][0]) - int(results[0][1])
    diff2 = int(results[1][0]) - int(results[1][1])
    if diff1 < diff2:
        return results[0]
    if diff1 > diff2:
        return reversed(results[1])
    if results[0][0] < results[1][0]:
        return results[0]
    if results[0][0] > results[1][0]:
        return reversed(results[1])
    if results[0][1] < results[1][1]:
        return results[0]
    return reversed(results[1])


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
        write(list(solve()))
        write("\n")
if tfile is not None: tfile.close()
