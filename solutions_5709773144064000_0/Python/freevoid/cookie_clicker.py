from __future__ import division
import sys


def time_to_win(c, f, x):
    time_spent_bying_factories = 0
    waiting_for_win = x / 2
    nfactories = 0

    if c >= x:
        return nfactories, waiting_for_win

    previous_estimation = waiting_for_win

    while True:
        nfactories += 1
        time_spent_bying_factories += c / (2 + (nfactories - 1)*f)
        waiting_for_win = x / (2 + f*nfactories)
        new_estimation = time_spent_bying_factories + waiting_for_win

        if new_estimation >= previous_estimation:
            break

        previous_estimation = new_estimation

    return nfactories, previous_estimation


def read_input(path):
    with open(path) as fp:
        # skip T, trust Google's input data
        fp.readline()
        for line in fp:
            yield map(float, line.split(' '))


def print_case_result(casenum, answer):
    print 'Case #%d: %.7f' % (casenum, answer)


if __name__ == '__main__':
    input_path = sys.argv[1]
    for i, test_case in enumerate(read_input(input_path)):
        c, f, x = test_case
        factories_bought, time_spent = time_to_win(c, f, x)
        print_case_result(i + 1, time_spent)
