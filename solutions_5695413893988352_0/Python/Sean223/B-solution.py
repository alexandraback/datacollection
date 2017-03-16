__author__ = 'sean'


# IN_FILE = 'test_input.txt'
# OUT_FILE = 'test_output.txt'

IN_FILE = 'B-small.in'
OUT_FILE = 'small_out.txt'

# IN_FILE = 'B-large.in'
# OUT_FILE = 'large_out.txt'


with open(IN_FILE, 'r') as fileIn:
    fileLines = fileIn.readlines()

it = iter(fileLines)
numbCases = int(next(it))
output = ""

TIE = 0
CODERS = 1
JAMMERS = -1


def do_match(pot_c, pot_j, coders, jammers):
    while len(pot_c) < len(coders):
        pot_c = '0' + pot_c
    while len(pot_j) < len(jammers):
        pot_j = '0' + pot_j

    for i in range(len(coders)):
        c, j = coders[i], jammers[i]
        if not c == '?' and not pot_c[i] == c:
            return False
        if not j == '?' and not pot_j[i] == j:
            return False
    return True


def does_c_match(pot_c, coders):
    while len(pot_c) < len(coders):
        pot_c = '0' + pot_c
    for i in range(len(coders)):
        if not coders[i] == '?' and not pot_c[i] == coders[i]:
            return False
    return True


def brute_force_solution(coders, jammers):
    best_so_far_c, best_so_far_j = 9999, 9999
    best_so_far_diff = 100000

    for poss_c in range(0, 10**(len(coders))):
        if not does_c_match(str(poss_c), coders):
            continue
        for poss_j in range(0, 10 ** (len(coders))):
            if do_match(str(poss_c), str(poss_j), coders, jammers):
                if abs(poss_c - poss_j) < best_so_far_diff:
                    best_so_far_diff = abs(poss_c - poss_j)
                    best_so_far_c, best_so_far_j = poss_c, poss_j

    rv_c, rv_j = str(best_so_far_c), str(best_so_far_j)
    while len(rv_c) < len(coders):
        rv_c = '0' + rv_c
    while len(rv_j) < len(jammers):
        rv_j = '0' + rv_j

    return rv_c, rv_j


def look_ahead(c_current, j_current, c_next, j_next):
    if c_next is None or j_next is None or c_next == '?' or j_next == '?':
        if c_current == '?' and j_current == '?':
            return '0', '0'
        elif c_current == '?':
            return j_current, j_current
        elif j_current == '?':
            return c_current, c_current
        else:
            raise Exception()

    if c_current == '?' and j_current == '?':
        both_zero = abs(int('0' + c_next) - int('0' + j_next))
        c_zero = abs(int('0' + c_next) - int('1' + j_next))
        j_zero = abs(int('1' + c_next) - int('0' + j_next))

        if both_zero == min(both_zero, c_zero, j_zero):
            return '0', '0'
        elif c_zero == min(both_zero, c_zero, j_zero):
            return '0', '1'
        else:
            return '1', '0'

    elif c_current == '?':
        c_digit = j_current
        c_equal = abs(int(c_digit + c_next) - int(j_current + j_next))

        if j_current == '9':
            c_greater = 1000000
        else:
            c_digit = str(int(j_current) + 1)
            c_greater = abs(int(c_digit + c_next) - int(j_current + j_next))

        if j_current == '0':
            c_lesser = 1000000
        else:
            c_digit = str(int(j_current) - 1)
            c_lesser = abs(int(c_digit + c_next) - int(j_current + j_next))

        if c_lesser == min(c_equal, c_greater, c_lesser):
            return str(int(j_current) - 1), j_current
        elif c_equal == min(c_equal, c_greater, c_lesser):
            return j_current, j_current
        else:
            return str(int(j_current) + 1), j_current

    else:
        flipped_answer_j, flipped_answer_c = look_ahead(j_current, c_current, j_next, c_next)
        return flipped_answer_c, flipped_answer_j


def solve(coders, jammers):
    optimal_coders = ""
    optimal_jammers = ""

    status = TIE

    for i in range(len(coders)):
        c, j = coders[i], jammers[i]

        c_next, j_next = None, None
        if i+1 < len(coders):
            c_next, j_next = coders[i+1], jammers[i+1]

        if not c == '?' and not j == '?':
            optimal_coders += c
            optimal_jammers += j
            if status == TIE and int(c) > int(j):
                status = CODERS
            elif status == TIE and int(c) < int(j):
                status = JAMMERS

        elif c == '?' and j == '?':
            if status == TIE:
                chosen_c, chosen_j = look_ahead(c, j, c_next, j_next)
                optimal_coders += chosen_c
                optimal_jammers += chosen_j

                if int(chosen_c) > int(chosen_j):
                    status = CODERS
                elif int(chosen_c) < int(chosen_j):
                    status = JAMMERS

            elif status == CODERS:
                optimal_coders += '0'
                optimal_jammers += '9'
            else:
                optimal_coders += '9'
                optimal_jammers += '0'

        elif c == '?':
            if status == TIE:
                chosen_c, chosen_j = look_ahead(c, j, c_next, j_next)
                optimal_coders += chosen_c
                optimal_jammers += chosen_j

                if int(chosen_c) > int(chosen_j):
                    status = CODERS
                elif int(chosen_c) < int(chosen_j):
                    status = JAMMERS

            elif status == CODERS:
                optimal_coders += '0'
                optimal_jammers += j
            else:
                optimal_coders += '9'
                optimal_jammers += j

        else:
            if status == TIE:
                chosen_c, chosen_j = look_ahead(c, j, c_next, j_next)
                optimal_coders += chosen_c
                optimal_jammers += chosen_j

                if int(chosen_c) > int(chosen_j):
                    status = CODERS
                elif int(chosen_c) < int(chosen_j):
                    status = JAMMERS

            elif status == CODERS:
                optimal_coders += c
                optimal_jammers += '9'
            else:
                optimal_coders += c
                optimal_jammers += '0'

    return optimal_coders, optimal_jammers


for case in range(numbCases):
    answer = ""

    [input_coders, input_jammers] = next(it).strip().split()

    best_c, best_j = brute_force_solution(input_coders, input_jammers)

    print("Case #{0}: completed: {1} {2}".format(str(case+1), best_c, best_j))
    line = "Case #{0}: {1} {2}\n".format(str(case+1), str(best_c), str(best_j))
    output += line


with open(OUT_FILE, 'w') as fileOut:
    fileOut.write(output)
