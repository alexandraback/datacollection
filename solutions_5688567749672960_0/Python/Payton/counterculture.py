def next_step(n):
    return n + 1


def next_swap(n):
    ss = str(n)[::-1]
    return int(ss.lstrip('0'))


def solve_digits(n_digits):
    if n_digits == 1:
        return 1
    elif n_digits == 2:
        return 10
    elif n_digits == 3:
        return 29
    elif n_digits == 4:
        return 138
    else:
        base = solve_digits(n_digits - 1)
        zeroes = n_digits - 1
        first_half_nines = zeroes / 2
        second_half_nines = zeroes - first_half_nines
        first_half_count = 10 ** (first_half_nines) - 1  # Literally count 10^n - 1
        second_half_count = 10 ** (second_half_nines) - 2  # there's already a 1 after swapping
        # base, first half, swap, second half, then last one
        return base + first_half_count + 1 + second_half_count + 1


def simple_solve(n):
    stringified = str(n)
    digits = len(stringified)
    base = solve_digits(digits)  # Steps to 10 ** n
    length = len(stringified)
    first_half = stringified[:length / 2]
    second_half = stringified[length / 2:]
    first_half_count = int(first_half[::-1])
    second_half_count = int(second_half)

    if first_half.rstrip('0') == '1':
        return base + second_half_count
    else:
        # Swap costs one, but we get the leftmost one on the right for free!
        return base + first_half_count + second_half_count


def solve(n):
    stringified = str(n)
    if len(stringified) == 1:
        return n
    if n == 10:
        return 10

    # Numbers that are x00...0000
    if len(stringified.rstrip('0')) == 1:
        return simple_solve(n - 1) + 1

    return simple_solve(n)


cases = input()
for ctr in xrange(cases):
    gg = input()
    # print 'Test solve', solve_digits(gg)
    answer = solve(gg)
    print 'Case #{}: {}'.format(ctr + 1, answer)


# 901 -> 1000 = 1
# Table of solutions:
# 100 - 29 steps (1 -> 91)
# 200 - 129 steps
# 300 - 100 (29) - 102 (31) - 201 (32) - 300 - (131)
# 1000 - 100 (29) - 109 (38) - 901 (39) - 1000 (138)
# 9999 - 1000 (138) - 1099 (237) - 9901 (238) - 9999 (336)
# 1999 - 1000 (138) - 1091 (229) - 1901 (230) - 1999 (328)
# 3000 == 2999 + 1
