import os

__author__ = 'dkopiychenko'


def solve(s):
    n = int(s)
    if n < 12:
        return n
    c = 0
    if n % 10 == 0:
        n = n - 1
        c += 1
        s = str(n)

    while n > 11:
        m = len(s)/2
        n1 = int(s[m:])
        ss = s[:m]
        n2 = int(ss[::-1])
        c += (n1 - 1)
        c += (n2 - 1)
        if n2 != 1: c += 1
        c += 2
        r = ''
        for k in range(len(s) - 1):
            r += '9'
        s = r
        n = int(s)


    return c + n



with open(os.path.expanduser("~/Downloads/A-large (2).in")) as f:
# with open(os.path.expanduser("~/gcj2015/A-test.in.txt")) as f:
    n = int(f.readline().strip('\n'))
    print n
    for i in range(n):
        s = f.readline().strip('\n')
        #res = solve(m)
        print 'Case #' + str(i+1) + ': ' + str(solve(s))
