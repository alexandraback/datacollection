# -*-coding:utf-8 -*

# import math
# from operator import itemgetter
# from fractions import Fraction
from functools import lru_cache

@lru_cache(maxsize=None)
def nb_possibilities(B):
    if B < 3:
        return 1
    else:
        return sum(nb_possibilities(i) for i in range(1, B))


def aux(b, m, init):

    if m == 0:
        return init
    else:
        if b == 0:
            return False
        elif b == 1:
            pass
        elif b == 2:
            init[-b][-b+1] = 1
        else:
            cur_m = m
            jump = 1
            while cur_m > 0:
                # if cur_m <= nb_possibilities(b-jump):
                aux(b-jump, min(cur_m, nb_possibilities(b-jump)), init)
                init[-b][-b + jump] = 1
                # print(init)
                cur_m -= nb_possibilities(b-jump)
                jump += 1


def main_func(B, M):
    if M <= nb_possibilities(B):
        init = [[0 for i in range(B)] for j in range(B)]
        aux(B, M, init)
        return 'POSSIBLE\n' + '\n'.join(''.join(str(n) for n in line) for line in init)
    else:
        return 'IMPOSSIBLE'


# print(main_func(4, 4))

# ------------------------------------------------------------------------------------------------------------------------------
# We apply mainFunc to each input
# ------------------------------------------------------------------------------------------------------------------------------

hl = 1  # "Header lines" :Number of lines at the beginning of the input file (header information)
lpc = 1  # "Lines per test case" number of lines for each entry of input
# (lpc will be used only if that number is the same for every case)
lineSep = "\n"  # Line separator
colSep = " "  # column separator

with open("input.txt", 'r') as inputFile:
    # ------------------------------------------------------------------------------------------------------------
    # Parsing the input
    # ------------------------------------------------------------------------------------------------------------
    # ------------------------------------------------------------------------
    # Parsing the header
    # ------------------------------------------------------------------------
    inputLines = inputFile.read().split(lineSep)
    while inputLines[-1] == '': del inputLines[-1]  # Deleting all empty lines at the end
    T = int(inputLines[0])  # Number of test cases
    # ------------------------------------------------------------------------

    # ------------------------------------------------------------------------
    # Parsing the body
    # ------------------------------------------------------------------------
    caseStartIndex = [hl]
    for i in range(T):  # caseStartIndex[T] = 1 + index of the last line
        # (ie : the index where would start case T+1 if it existed). In most cases we won't use it.
        nbLinesForThisCase = lpc
        # nbLinesForThisCase = int(inputLines[caseStartIndex[i]]) + 1
        caseStartIndex.append(caseStartIndex[i] + nbLinesForThisCase)
    # ------------------------------------------------------------------------

    # ------------------------------------------------------------------------
    # Formatting the input so that it's ready to be passed to mainFunc(*input)
    # ------------------------------------------------------------------------
    formattedInput = \
        [
            [
                int(n) for n in inputLines[caseStartIndex[caseID]].split(colSep)
            ]
            for caseID in range(T)
        ]
    # ------------------------------------------------------------------------
    # ------------------------------------------------------------------------------------------------------------

    # ------------------------------------------------------------------------------------------------------------
    # Generating the output : Apply mainFunc() to each test case
    # ------------------------------------------------------------------------------------------------------------
    outputString = "\n".join(["Case #"+str(i+1)+": "+main_func(*inp) for i, inp in enumerate(formattedInput)])
    print("output:")
    print(outputString)
    with open("output.txt", "w") as outputFile:
        outputFile.write(outputString)
    # ------------------------------------------------------------------------------------------------------------

# ------------------------------------------------------------------------------------------------------------------------------