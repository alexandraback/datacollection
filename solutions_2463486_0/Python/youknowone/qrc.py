
from math import sqrt, ceil, trunc

def is_palindrome(num):
    snum = str(num)
    lsnum = len(snum)
    for i in xrange(0, lsnum / 2):
        if snum[i] != snum[lsnum - i - 1]:
            return False
    return True


def fairsquare(start, end):
    qstart = int(ceil(sqrt(start)))
    qend = trunc(sqrt(end))

    c = 0
    for rt in xrange(qstart, qend + 1):
       if is_palindrome(rt) and is_palindrome(rt ** 2):
            c += 1
    return c

if __name__ == '__main__':
    count = input()
    for x in xrange(1, count + 1):
        start, end = map(int, raw_input().split(' '))
        count = fairsquare(start, end)
        print 'Case #%d:' % x, count