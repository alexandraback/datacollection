from sys import stdin


def read_str(): return stdin.readline().rstrip('\n')
def read_strs(): return stdin.readline().rstrip('\n').split()
def read_int(): return int(stdin.readline())
def read_ints(): return map(int, stdin.readline().split())
def read_floats(): return map(float, stdin.readline().split())


MAX = 20


def prepare_solutions():
    solutions = []
    for i in range(1, MAX + 1):
        solutions.append([])
        for j in range(1, MAX + 1):
            solutions[-1].append([])
            for k in range(1, j + 1):
                if i > 6 or i > 2 and k < i - 1:
                    possible = False
                else:
                    possible = (j * k) % i == 0
                solutions[-1][-1].append(possible)
                #print(i, j, k, possible)
    return solutions
    

def solve_case(solutions):
    X, R, C = read_ints()
    if C > R:
        R, C = C, R
    return 'GABRIEL' if solutions[X - 1][R - 1][C - 1] else 'RICHARD'

    
def main():
    solutions = prepare_solutions()
    cases = read_int()
    for case in range(1, cases + 1):
        print('Case #{}: {}'.format(case, solve_case(solutions)))


main()
