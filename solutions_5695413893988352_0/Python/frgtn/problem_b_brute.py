from collections import Counter
import itertools
import sys


def resolve_common_prefix(C, J):
    prefix = []
    for i in range(len(C)):
        if C[i] == '?' and J[i] == '?':
            prefix.append(0)
        elif C[i] == '?':
            prefix.append(int(J[i]))
        elif J[i] == '?':
            prefix.append(int(C[i]))
        elif C[i] == J[i]:
            prefix.append(int(C[i]))
        else:
            break
    return prefix


def to_suffix(seq, replacement):
    result = []
    for c in seq:
        if c == '?':
            result.append(replacement)
        else:
            result.append(int(c))
    return result


def bruteforce(C, J):
    sample = '0123456789'
    counts = Counter(C) + Counter(J)
    choice_size = counts.get('?', 0)
    result_C = None
    result_J = None
    min_diff = 99999999999999999999999999999999999999999999999
    for choice in itertools.product(sample, repeat=choice_size):
        choice = list(choice)
        tmp_C = ''
        for c in C:
            tmp_C += choice.pop(0) if c == '?' else c
        tmp_J = ''
        for c in J:
            tmp_J += choice.pop(0) if c == '?' else c
        diff = abs(int(tmp_C) - int(tmp_J))
        if result_C is None or diff < min_diff:
            min_diff = diff
            result_C = tmp_C
            result_J = tmp_J
        elif diff == min_diff:
            if int(result_C) > int(tmp_C):
                min_diff = diff
                result_C = tmp_C
                result_J = tmp_J
            elif int(result_C) == int(tmp_J):
                if int(result_J) > int(tmp_J):
                    min_diff = diff
                    result_C = tmp_C
                    result_J = tmp_J
    return result_C, result_J


def solve(T, C, J):
    result_C, result_J = bruteforce(C, J)

    print('Case #{}: {} {}'.format(T, result_C, result_J))


def main():
    n_cases = int(sys.stdin.readline().strip())
    for case in range(n_cases):
        C, J = sys.stdin.readline().strip().split(' ')
        solve(case + 1, C, J)


if __name__ == '__main__':
    main()
