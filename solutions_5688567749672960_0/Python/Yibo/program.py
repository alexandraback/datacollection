#!/usr/bin/python2.7


f = open('input.txt', 'r')
T = int(f.readline())

def reverse(s):
    return s[::-1]

def allAre(s, c):
    if s == '':
        return True
    else:
        return s[0] == c and allAre(s[1:], c)

def solve(n, l):
    s = str(n)
    a = s[:l / 2]
    b = s[l / 2:]

    if l == 1:
        return n
    elif s[0] == '1' and allAre(s[1:], '0'):
        return 1 + solve(int('9' * (l - 1)), l - 1)
    elif a[0] == '1' and allAre(a[1:], '0'):
        return int(b) + solve(pow(10, l - 1), l)
    elif s[l - 1] == '0':
        return 1 + solve(n - 1, l)
    else:
        return int(b) + int(reverse(a)) + solve(pow(10, l - 1), l)

for t in range(T):
    n = int(f.readline())

    print "Case #" + str(t + 1) + ":",
    print solve(n, len(str(n)))

