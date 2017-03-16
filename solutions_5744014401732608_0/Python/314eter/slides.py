#! /usr/bin/env python3
newline = False


def read_problem():
    return tuple(int(c) for c in input().split())


def solve(problem):
    B, M = problem
    if M > 2 ** (B - 2):
        return None
    if M == 2 ** (B - 2):
        first = '0' + '1' * (B - 1)
    else:
        first = bin(M)[2:]
        fmt = "{0:0" + str(B - 1) + "b}"
        first = fmt.format(M) + '0'
    return [first] + ['0' * i + '1' * (B - i) for i in range(2, B + 1)]


def print_solution(slides):
    if slides is None:
        print("IMPOSSIBLE")
    else:
        print("POSSIBLE")
        print(*slides, sep='\n')


cases = int(input())
for n in range(1, cases + 1):
    problem = read_problem()
    solution = solve(problem)
    print("Case #{0}:".format(n), end='\n' if newline else ' ')
    print_solution(solution)
