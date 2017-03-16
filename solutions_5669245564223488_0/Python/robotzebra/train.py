import sys

def initialize(fname):
    # open
    with open(fname) as f:
        lines = f.readlines()

    # clean
    for i, line in enumerate(lines):
        lines[i] = line.split()

    # parse
    NUM_TESTS = int(lines.pop(0)[0])
    tests = []

    for test in range(NUM_TESTS):
        num_words = int(lines.pop(0)[0])
        words = lines.pop(0)
        tests.append((num_words, words))

    return tests


def finalize(answers, out):
    for test_num, answer in enumerate(answers, 1):
        print('Case #{}: {}'.format(test_num, answer))
        print('Case #{}: {}'.format(test_num, answer), file=out)

def shrink(word):
    previous = None
    result = ''
    for c in word:
        if c != previous:
            result += c
            previous = c
    return result

def process_test(test):
    def checker(words):
        bigword = ''.join(words)
        closed = set()
        previous = None
        for c in bigword:
            if c != previous:
                if c in closed:
                    return False
                closed.add(previous)
            previous = c
        return True

    from itertools import permutations
    words = test[1]

    words = map(shrink, words)

    count = 0
    for perm in permutations(words):
        count += checker(perm)
    return count % 1000000007

def main(fname, write_to=sys.stdout):
    tests = initialize(fname)
    from multiprocessing import Pool
    pool = Pool()
    answers = pool.map(process_test, tests)
    finalize(answers, write_to)


if __name__ == '__main__':
    in_fname = sys.argv[1]
    out_fname = in_fname.replace('in', 'out')
    with open(out_fname, 'w') as out:
        main(in_fname, write_to=out)
