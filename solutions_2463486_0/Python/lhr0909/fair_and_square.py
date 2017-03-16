#http://oeis.org/A002779

import numpy as np

num_set = set()

num_set.add(1)
num_set.add(4)
num_set.add(9)
num_set.add(121)
num_set.add(484)


def isPalindrome(n):
    a = str(n)
    b = ''.join(reversed(list(str(n))))
    return a == b


def solve(filename):
    fin = open(filename + '.in', 'r')
    fout = open(filename + '.out', 'w')

    T = int(fin.readline())
    for case in xrange(T):
        answer = 0
        A, B = map(int, fin.readline().strip().split(' '))

        # This is not needed for the small case
        # i = 1
        # while i*i <= B:
        #     if isPalindrome(i * i) and isPalindrome(i):
        #         num_set.add(i * i)
        #     i += 1

        answer = len(filter(lambda x: A <= x <= B, num_set))
        print sorted(list(num_set))
        print answer
        fout.write(('Case #%d: ' % (case + 1)) + str(answer) + '\n')

    fin.close()
    fout.close()


if __name__ == "__main__":
    # solve("C-tiny")
    solve("C-small-attempt0")
    # solve("C-large")