#http://oeis.org/A002779

import numpy as np

num_set = {1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201,
           104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001L, 10221412201L, 12102420121L,
           12345654321L, 40000800004L, 1000002000001L, 1002003002001L, 1004006004001L, 1020304030201L, 1022325232201L,
           1024348434201L, 1210024200121L, 1212225222121L, 1214428244121L, 1232346432321L, 1234567654321L,
           4000008000004L, 4004009004004L}

def isPalindrome(n):
    a = str(n)
    b = ''.join(reversed(list(str(n))))
    return a == b


def solve(filename):
    fin = open(filename + '.in', 'r')
    fout = open(filename + '.out', 'w')

    T = int(fin.readline())
    for case in xrange(T):
        A, B = map(int, fin.readline().strip().split(' '))

        # This is not needed for the case

        # i = 1
        # while i * i <= 100000000000000:
        #     if isPalindrome(i * i) and isPalindrome(i):
        #         num_set.add(i * i)
        #         print num_set
        #     i += 1

        answer = len(filter(lambda x: A <= x <= B, num_set))
        #print sorted(list(num_set))
        print answer
        fout.write(('Case #%d: ' % (case + 1)) + str(answer) + '\n')

    fin.close()
    fout.close()


if __name__ == "__main__":
    # print 10**14
    # solve("C-tiny")
    # solve("C-small-attempt0")
    solve("C-large-1")