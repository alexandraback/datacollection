import sys
from collections import Counter

def read_ints(inp):
    return [int(x) for x in inp.readline().split()]

def handle(inp, i):
    letters = inp.readline().strip()

    word_and_signal = [
        ["ZERO", "Z"],
        ["EIGHT", "G"],
        ["SIX", "X"],
        ["FOUR", "U"],
        ["FIVE", "F"],
        ["THREE", "H"],
        ["TWO", "W"],
        ["SEVEN", "V"],
        ["NINE", "I"],
        ["ONE", "O"]]

    words = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

    lcs = Counter(letters)

    a0 = lcs["Z"]
    a8 = lcs["G"]
    a6 = lcs["X"]
    a4 = lcs["U"]
    a5 = lcs["F"] - a4
    a3 = lcs["H"] - a8
    a2 = lcs["W"]
    a7 = lcs["V"] - a5
    a9 = lcs["I"] - (a8 + a6 + a5)
    a1 = lcs["O"] - (a0 + a4 + a2)

    return ("0" * a0) +    ("1" * a1) +    ("2" * a2) +    ("3" * a3) +    ("4" * a4) +    ("5" * a5) +    ("6" * a6) +    ("7" * a7) +    ("8" * a8) +    ("9" * a9)

f_in = sys.stdin
N = int(f_in.readline())
f_out = sys.stdout

for i in range(N):
    f_out.write("Case #%i: " % (i+1))
    result = handle(f_in, i)
    f_out.write(result)
    f_out.write("\n")
