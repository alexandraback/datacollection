from solver import solver
from collections import Counter

STEP1 = {
    'Z': ('ZERO', 0),
    'W': ('TWO', 2),
    'U': ('FOUR', 4),
    'X': ('SIX', 6),
    'G': ('EIGHT', 8),
    }

STEP2 = {
    'O': ('ONE', 1),
    'H': ('THREE', 3),
    'F': ('FIVE', 5),
    'S': ('SEVEN', 7),
    }

STEP3 = {
    'I': ('NINE', 9)
    }

STEPS = (STEP1, STEP2, STEP3)

def solve(arg):
    counter = Counter(arg)
    for dct in STEPS:
        for key, (word, number) in dct.items():
            if key in counter:
                count = counter[key]
                yield from [number] * count
                for letter in word:
                    counter[letter] -= count
    assert all(v == 0 for v in counter.values())

@solver
def problem(lines):
    res = sorted(solve(lines[0]))
    return ''.join(map(str, res))

if __name__ == '__main__':
    problem.from_cli()
