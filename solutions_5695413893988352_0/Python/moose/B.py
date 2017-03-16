#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""Solution for problem B to Codejam 2016, Round 1B of Martin Thoma."""


def try_equal(C, J):
    equal_possible = True
    for i in range(len(C)):
        if C[i] != J[i]:
            equal_possible = False
    if not equal_possible:
        return C, J
    for i in range(len(C)):
        if C[i] == '?':
            C = list(C)
            C[i] = J[i]
            C = "".join(C)
        elif J[i] == '?':
            J = list(J)
            J[i] = C[i]
            J = "".join(J)
    return C, J


def fill(C, J, number):
    counter = 0
    for i in range(len(C)):
        if C[i] == '?':
            C = list(C)
            C[i] = number[counter]
            C = "".join(C)
            counter += 1
    for i in range(len(J)):
        if J[i] == '?':
            J = list(J)
            J[i] = number[counter]
            J = "".join(J)
            counter += 1
    return C, J


def brute(C, J):
    qmarks = C.count('?') + J.count('?')
    min_c, min_j, diff = None, None, None
    for i in range(10**qmarks):
        c_tmp, j_tmp = fill(C, J, str(i).zfill(qmarks))
        diff_tmp = abs(int(c_tmp) - int(j_tmp))
        if diff is None or (diff_tmp < diff) or (diff_tmp == diff and int(c_tmp) < int(min_c)):
            min_c = c_tmp
            min_j = j_tmp
            diff = diff_tmp
    return min_c, min_j


def solve(C, J):
    """Solve."""
    C, J = try_equal(C, J)
    C, J = brute(C, J)
    # if not "?" in C and not "?" in J:
    #     return C, J
    # c_bigger = None
    # stopped_at = None
    # for i in range(len(C)):
    #     if C[i] == J[i]:
    #         if C[i] == '?':
    #             C = list(C)
    #             C[i] = "0"
    #             C = "".join(C)
    #             J = list(J)
    #             J[i] = "0"
    #             J = "".join(J)
    #     elif C[i] == '?':
    #         C = list(C)
    #         C[i] = J[i]
    #         C = "".join(C)
    #     elif J[i] == '?':
    #         J = list(J)
    #         J[i] = C[i]
    #         J = "".join(J)
    #     else:
    #         c_bigger = C[i] > J[i]
    #         stopped_at = i
    #         break
    # if not "?" in C and not "?" in J:
    #     return C, J
    # for i in range(stopped_at+1, len(C)):
    #     if C[i] == '?':
    #         if c_bigger:
    #             C = list(C)
    #             C[i] = "0"
    #             C = "".join(C)
    #         else:
    #             C = list(C)
    #             C[i] = "9"
    #             C = "".join(C)
    #     if J[i] == '?':
    #         if c_bigger:
    #             J = list(J)
    #             J[i] = "9"
    #             J = "".join(J)
    #         else:
    #             J = list(J)
    #             J[i] = "0"
    #             J = "".join(J)
    return C, J


if __name__ == "__main__":
    testcases = input()

    for caseNr in xrange(1, testcases+1):
        cipher = raw_input()
        C, J = cipher.split(" ")
        print("Case #%i: %s" % (caseNr, " ".join(solve(C, J))))
