#!/usr/bin/python

import sys

def get_file(argv):
    if len(argv) == 1:
        return "a.in"
    else:
        return "a_%s.in" % (argv[1])

def get_file_out(argv):
    if len(argv) == 1:
        return "a.out"
    else:
        return "a_%s.out" % (argv[1])

def print_answer(t, answer, f):
    answer = "Case #%d: %s" % (t, answer)
    print answer
    f.write(answer)
    f.write("\n")

def get_number(S):
    L = list(S)
    M = {}
    for c in S:
        if c in M:
            M[c] = M[c] + 1
        else:
            M[c] = 1
    O = ['Z', 'W', 'U', 'X', 'G', 'FI', 'SV', 'HR', 'NI', 'ON']
    uniques = {
        'Z': ['Z', 'E', 'R', 'O'],
        'W': ['T', 'W', 'O'],
        'U': ['F', 'O', 'U', 'R'],
        'X': ['S', 'I', 'X'],
        'G': ['E', 'I', 'G', 'H', 'T'],
        'FI': ['F', 'I', 'V', 'E'],
        'SV': ['S', 'E', 'V', 'E', 'N'],
        'HR': ['T', 'H', 'R', 'E', 'E'],
        'NI': ['N', 'I', 'N', 'E'],
        'ON': ['O', 'N', 'E'],
    }
    assert len(uniques) == 10
    mapping = [0, 2, 4, 6, 8, 5, 7, 3, 9, 1]
    assert len(mapping) == 10
    numbers = []
    for check in xrange(0, len(O)):
        uc = O[check]
        found_all = True
        for test in uc:
            if test not in M or M[test] < 1:
                found_all = False
                break
        if found_all:
            to_remove = len(S)
            for test in uc:
                to_remove = min(M[test], to_remove)
            for i in xrange(0, to_remove):
                numbers.append(str(mapping[check]))
                for c in uniques[uc]:
                    M[c] = M[c] - 1
    numbers.sort()
    return ''.join(numbers)

def main(argv):
    f = open(get_file(argv), 'r')
    f_out = open(get_file_out(argv), 'w')
    T = int(f.readline())
    for t in xrange(1, T+1):
        S = f.readline().strip()
        number = get_number(S)
        print_answer(t, number, f_out)


if __name__ == "__main__":
    main(sys.argv)
