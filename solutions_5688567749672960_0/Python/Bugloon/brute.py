import sys

def parse_tests(infile):
    T = int(infile.readline())
    for _ in range(T):
        yield infile.readline().strip()


def min_steps(N):
    N = int(N)
    c = 1
    possible = set([1])
    seen = set([1])
    while True:
        if N in possible:
            return c
        new_possible = set()
        for p in possible:
            if p+1 not in seen:
                new_possible.add(p+1)
            rev = int("".join(reversed(str(p))))
            if rev not in seen:
                new_possible.add(rev)
        seen.update(new_possible)
        possible = new_possible
        c += 1
            

def print_result(case, result):
    print("Case #{}: {}".format(case, result))

def main():
    for case, test in enumerate(parse_tests(sys.stdin), 1):
        result = min_steps(test)
        print_result(case, result)

if __name__ == "__main__":
    main()
