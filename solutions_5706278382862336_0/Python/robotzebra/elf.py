import sys

def initialize(fname):
    # open
    with open(fname) as f:
        lines = f.readlines()

    # clean
    for i, line in enumerate(lines):
        lines[i] = [int(n) for n in line.split('/')]

    # parse
    NUM_TESTS = lines.pop(0)[0]
    tests = []

    for test in range(NUM_TESTS):
        tests.append(lines.pop(0))

    return tests


def finalize(answers, out):
    for test_num, answer in enumerate(answers, 1):
        print('Case #{}: {}'.format(test_num, answer))
        print('Case #{}: {}'.format(test_num, answer), file=out)


def process_test(test, pwrs=[2**(-i) for i in range(1, 41)]):
    print(test)
    numer, denom = test
    # frac = numer / denom
    for maxpwr in pwrs:
        used = set()
        frac = numer / denom

        for i, p in enumerate(pwrs, 1):
            if frac >= p:
                frac -= p
                used.add(i)
                # print(used)
                if frac == 0:
                    break
        if frac == 0:
            return min(used)
    return 'impossible'


def main(fname, write_to=sys.stdout):
    tests = initialize(fname)
    answers = [process_test(t) for t in tests]
    finalize(answers, write_to)


if __name__ == '__main__':
    in_fname = sys.argv[1]
    out_fname = in_fname.replace('in', 'out')
    with open(out_fname, 'w') as out:
        main(in_fname, write_to=out)
