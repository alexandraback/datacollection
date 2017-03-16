import sys
from string import ascii_uppercase

nums = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
nums = [tuple(num.count(l) for l in ascii_uppercase) for num in nums]


def run(filename):
    lines = open(filename + ".in").read().split("\n")[1:]  # remove the T
    fout = open(filename + ".out", "w")
    for t, line in enumerate(lines):
        value = tuple(line.count(l) for l in ascii_uppercase)
        result = solve(value)
        print("Case #{}: {}".format(t + 1, result, file=fout))
#        print("Case #{}: {}".format(t + 1, result))
    fout.close()


CACHE = {tuple([0] * 26): ""}
def solve(letters):
    if letters not in CACHE:
        for i, num in enumerate(nums):
            newletters = tuple(letter - numletters for letter, numletters in zip(letters, num))
            if not [x for x in newletters if x < 0] and solve(newletters) is not None:
                    CACHE[letters] = str(i) + solve(newletters)
                    break
        if letters not in CACHE:
            CACHE[letters] = None
    return CACHE[letters]


if __name__ == '__main__':
    run(sys.argv[1])
