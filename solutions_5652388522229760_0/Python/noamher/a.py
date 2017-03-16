import os
import sys
from sets import Set


def main():
    if len(sys.argv) != 2:
        print 'usage: a.py <input_file>'
        sys.exit(1)

    with open(sys.argv[1], 'r') as f, open('res', 'w') as out:
        [count] = map(int, f.readline().split())
        for i in xrange(count):
            [num] = map(int, f.readline().split())
            out.write('Case #' + str(i+1) + ': ' + str(find_last(num)) + '\n')

def find_last(num):
    # print num
    if (num == 0):
        return "INSOMNIA"

    digits = set()
    i = 0
    while (len(digits) < 10):
        i += 1
        # print find_digits(num * i)
        digits = digits.union(find_digits(num * i))
        # print digits
    return num * i

def find_digits(num):
    digits = set()
    while (num > 0):
        digits.add(num % 10)
        num /= 10
    return digits




if __name__ == "__main__":
    main()