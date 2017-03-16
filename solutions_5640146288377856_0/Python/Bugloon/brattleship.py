import sys

def parse_testcases(infile):
    T = int(infile.readline())
    for _ in range(T):
        yield map(int, infile.readline().split())

def solve_testcase(R, C, W):
    result = 0
    while C >= 2*W:
        result += R
        C -= W
    result += R - 1
    if C != W:
        result += 1
    result += W
    return result

def print_result(outfile, case, result):
    outfile.write("Case #{}: {}\n".format(case, result))

def main():
    for num, testcase in enumerate(parse_testcases(sys.stdin), 1):
        result = solve_testcase(*testcase)
        print_result(sys.stdout, num, result)

if __name__ == "__main__":
    main()