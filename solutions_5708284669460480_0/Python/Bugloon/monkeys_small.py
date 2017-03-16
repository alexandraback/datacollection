import sys
from itertools import product, repeat

def parse_testcases(infile):
    T = int(infile.readline())
    for _ in range(T):
        K, L, S = map(int, infile.readline().split())
        keys = infile.readline()[:K]
        word = infile.readline()[:L]
        yield S, keys, word

def solve_testcase(S, keys, word):
    total = 0
    max_in_output = 0
    word_len = len(word)
    for possibility in product(*repeat(keys, S)):
        output = "".join(possibility)
        output_count = 0
        for pos in range(S - word_len + 1):
            if output[pos:].startswith(word):
                output_count += 1
        total += output_count
        if output_count > max_in_output:
            max_in_output = output_count
    expected_bananas = float(total) / (len(keys) ** S)
    return max_in_output - expected_bananas

def print_result(outfile, num, result):
    outfile.write("Case #{}: {:.7f}\n".format(num, result))

def main():
    for num, testcase in enumerate(parse_testcases(sys.stdin), 1):
        result = solve_testcase(*testcase)
        print_result(sys.stdout, num, result)

if __name__ == "__main__":
    main()