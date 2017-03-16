FILE_NAME_PREFIX = 'A-large'


def min_gen(num, den, min_val):
    if (den%2) != 0:
        return -1

    if num == den:
        return min_val
    elif (num*2) == den:
        return min_val+1
    elif (num*2) > den:
        return min(min_val+1, min_gen(num-(den/2), den/2, min_val+1))
    else:  #num < den/2
        return min_gen(num, den/2, min_val+1)


def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


def solve(num, den):
    gcd_val = gcd(num, den)
    return min_gen(num/gcd_val, den/gcd_val, 0)


if __name__ == '__main__':
    input_file = open('in/' + FILE_NAME_PREFIX + '.in', 'r')
    output_file = open('out/' + FILE_NAME_PREFIX + '.out', 'w')
    test_case_nb = int(input_file.readline())

    for case in range(test_case_nb):
        num, den = [int(x) for x in input_file.readline().split('/')]
        res = solve(num, den)

        output_file.write("Case #" + str(case + 1) + ": " + (str(res) if res >= 0 else "impossible") + '\n')

    input_file.close()
    output_file.close()
