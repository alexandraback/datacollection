def solve_pow10(number):
    if number == 1:
        return 1
    elif number == 10:
        return 10
    else:
        return solve(number - 1) + 1


def solve(number):
    stringified = str(number)
    base10 = int('1' + '0' * (len(stringified) - 1))
    base = solve_pow10(base10)

    if number < 10:
        return number

    if base10 == number:
        return base

    no_swap = number - base10 + base
    length = len(stringified)
    first_half = stringified[:length / 2]
    second_half = stringified[length / 2:]
    first_half_count = int(first_half[::-1])
    second_half_count = int(second_half)

    if second_half.strip('0') != '':
        with_swap = base + first_half_count + second_half_count
    else:
        # print 'Bawal mag swap', number
        with_swap = solve(number - 1) + 1

    # print 'Solve:', number, no_swap, with_swap
    return min(no_swap, with_swap)


cases = input()
for ctr in xrange(cases):
    gg = input()
    # print 'Test solve', solve_digits(gg)
    answer = solve(gg)
    print 'Case #{}: {}'.format(ctr + 1, answer)


# 901 -> 1000 = 1
# Table of solutions:
# 100 - 29 steps (1 -> 19 -> 91 -> 100)
# 200 - 100 (29) - 200 (129)
# 201 - 100 (29) - 102 (31) - 201 (32)
# 300 - 100 (29) - 102 (31) - 201 (32) - 300 - (131)
# 1000 - 100 (29) - 109 (38) - 901 (39) - 1000 (138)
# 9999 - 1000 (138) - 1099 (237) - 9901 (238) - 9999 (336)
# 1999 - 1000 (138) - 1091 (229) - 1901 (230) - 1999 (328)
# 3000 - 2999 + 1
# 9001 - blah
