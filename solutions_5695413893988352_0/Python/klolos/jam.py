#!/usr/bin/env python

import sys


def print_result(result, i):
    sys.stdout.write("Case #%s: %s\n" % (i, result))


def readline():
    return sys.stdin.readline().rstrip('\n')


def splitline(f):
    return map(f, readline().split())


def best_solution(sols):
    diffs = [abs(int(s[0]) - int(s[1])) for s in sols]
    sols2 = [s for s in sols if abs(int(s[0]) - int(s[1])) == min(diffs)]
    if len(sols2) == 1:
        return sols2[0]

    cs = [int(s[0]) for s in sols2]
    sols3 = [s for s in sols2 if int(s[0]) == min(cs)]
    if len(sols3) == 1:
        return sols3[0]

    js = [int(s[1]) for s in sols3]
    sols4 = [s for s in sols3 if int(s[1]) == min(js)]
    return sols4[0]

def solve1(C, J, greater):
    if not len(C):
        return "", ""

    if greater == "C":
        if C[0] == "?":
            C[0] = "0"
        if J[0] == "?":
            J[0] = "9"

        c, j = solve1(C[1:], J[1:], "C")
        return str(C[0]) + c, str(J[0]) + j

    elif greater == "J":
        if C[0] == "?":
            C[0] = "9"
        if J[0] == "?":
            J[0] = "0"
        c, j = solve1(C[1:], J[1:], "J")
        return str(C[0]) + c, str(J[0]) + j

    else:
        if C[0] == "?" and J[0] == "?":
            sols = []
            c, j = solve1(C[1:], J[1:], None)
            sols.append(("0" + c, "0" + j))

            c, j = solve1(C[1:], J[1:], "C")
            sols.append(("1" + c, "0" + j))

            c, j = solve1(C[1:], J[1:], "J")
            sols.append(("0" + c, "1" + j))

        elif C[0] == "?":
            sols = []
            if J[0] != "9":
                c, j = solve1(C[1:], J[1:], "C")
                sols.append((str(int(J[0]) + 1) + c, str(J[0]) + j))

            if J[0] != "0":
                c, j = solve1(C[1:], J[1:], "J")
                sols.append((str(int(J[0]) - 1) + c, str(J[0]) + j))

            c, j = solve1(C[1:], J[1:], None)
            sols.append((str(J[0]) + c, str(J[0]) + j))

        elif J[0] == "?":
            sols = []
            if C[0] != "9":
                c, j = solve1(C[1:], J[1:], "J")
                sols.append((str(C[0]) + c, str(int(C[0]) + 1) + j))

            if C[0] != "0":
                c, j = solve1(C[1:], J[1:], "C")
                sols.append((str(C[0]) + c, str(int(C[0]) - 1) + j))

            c, j = solve1(C[1:], J[1:], None)
            sols.append((str(C[0]) + c, str(C[0]) + j))

        else:
            if int(C[0]) > int(J[0]):
                c, j = solve1(C[1:], J[1:], "C")
            elif int(C[0]) < int(J[0]):
                c, j = solve1(C[1:], J[1:], "J")
            else:
                c, j = solve1(C[1:], J[1:], None)
            return str(C[0]) + c, str(J[0]) + j

    return best_solution(sols)

def solve():
    C, J = splitline(list)
    c, j = solve1(C, J, None)
    return "%s %s" % (c, j)


def main():
    for i in range(int(readline())):
        print_result(solve(), i + 1)


if __name__ == '__main__':
    main()
