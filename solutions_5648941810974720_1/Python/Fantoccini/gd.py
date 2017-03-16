from multiprocessing import Pool
from collections import defaultdict


def solve(line):
    res = ""
    count = defaultdict(lambda: 0)
    for ch in line.strip():
        count[ch] = count[ch] + 1
    Z = count['Z']
    count['Z'] -= Z
    count['E'] -= Z
    count['R'] -= Z
    count['O'] -= Z
    res += "0" * Z

    W = count['W']
    count['T'] -= W
    count['W'] -= W
    count['O'] -= W

    U = count['U']
    count['F'] -= U
    count['O'] -= U
    count['U'] -= U
    count['R'] -= U

    O = count['O']
    count['O'] -= O
    count['N'] -= O
    count['E'] -= O
    res += "1" * O
    res += "2" * W

    R = count['R']
    count['T'] -= R
    count['H'] -= R
    count['R'] -= R
    count['E'] -= R
    count['E'] -= R
    res += "3" * R
    res += "4" * U

    F = count['F']
    count['F'] -= F
    count['I'] -= F
    count['V'] -= F
    count['E'] -= F
    res += "5" * F

    X = count['X']
    count['S'] -= X
    count['I'] -= X
    count['X'] -= X
    res += "6" * X

    V = count['V']
    count['S'] -= V
    count['E'] -= V
    count['V'] -= V
    count['E'] -= V
    count['N'] -= V
    res += "7" * V

    T = count['T']
    count['E'] -= T
    count['I'] -= T
    count['G'] -= T
    count['H'] -= T
    count['T'] -= T
    res += "8" * T

    res += "9" * count['I']

    return res



p = Pool(8)
with open("in.txt", "r") as fin:
    results = p.map(solve, fin.readlines()[1:])
    with open("out.txt", "w") as fout:
        i = 0
        for res in results:
            i += 1
            fout.write("Case #%d: %s\n" % (i, str(res)))
