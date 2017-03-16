# Nikita Kouevda
# 2013/04/12

import sys


def is_palindrome(n):
    s = str(n)
    return s == s[::-1]


def main():
    if len(sys.argv) != 2:
        print('Please specify an input file')
        sys.exit(1)

    with open(sys.argv[1], 'r') as in_file:
        content = in_file.read().strip()

    lines, cases = content.split('\n'), []

    for line in lines[1:]:
        cases.append(tuple(int(n) for n in line.split()))

    for case_num, case in enumerate(cases):
        count = 0

        lower, upper = int((case[0] - 1) ** 0.5) + 1, int((case[1]) ** 0.5)

        for root in range(lower, upper + 1):
            if is_palindrome(root):
                square = root * root

                if is_palindrome(square):
                    count += 1

        print('Case #{0}: {1}'.format(case_num + 1, count))


if __name__ == '__main__':
    main()
