import sys

def parse_testcases(infile):
    T = int(infile.readline())
    for _ in range(T):
        C, D, V = map(int, infile.readline().split())
        Ds = map(int, infile.readline().split())[:D]
        yield C, V, Ds

def solve_testcase(C, V, Ds):
    max_so_far = 0
    added = 0
    while max_so_far < V:
        head = Ds[0] if Ds else None
        if head is None or head > max_so_far + 1:
            new_coin = max_so_far + 1
            added += 1
        else:
            new_coin = head
            Ds = Ds[1:]
        max_so_far = C * new_coin + max_so_far
    return added

def print_result(outfile, testnum, result):
    outfile.write("Case #{}: {}\n".format(testnum, result))

def main():
    for num, testcase in enumerate(parse_testcases(sys.stdin), 1):
        result = solve_testcase(*testcase)
        print_result(sys.stdout, num, result)

if __name__ == "__main__":
    main()