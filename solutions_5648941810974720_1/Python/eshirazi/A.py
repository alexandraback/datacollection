import StringIO
from ecodejam.input_parser import *
import numpy as np
import string

letters_in_english = len(string.ascii_uppercase)
SFAROT = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]


def count_letters(input_string):
    result = [0] * letters_in_english
    for i in input_string:
        char_index = ord(i) - ord('A')
        result[char_index] += 1
    return result

DIGITS_PRICE = [count_letters(i) for i in SFAROT]

def solve(case_index):
    word = read_word()
    next_line()
    a = DIGITS_PRICE
    a = np.array(a)
    a = a.transpose()
    b = np.array(count_letters(word))
    solution = [int(round(i)) for i in list(np.linalg.lstsq(a, b)[0])]
    return "".join(str(i) * solution[i] for i in xrange(10))

SAMPLE = """
4
OZONETOWER
WEIGHFOXTOURIST
OURNEONFOE
ETHER
"""

if __name__ == "__main__":
    set_parsed_input(
        StringIO.StringIO(SAMPLE)
    )
    run_solver(solve)
