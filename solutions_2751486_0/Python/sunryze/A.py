# Google Code Jam 2013, Round 1C, Problem A
#


import sys, re


def solve(num, s, n):
    cs = [True] * len(s)
    for i in xrange(len(s)):
        c = s[i]
        if c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u':
            cs[i] = False
    m = [False] * len(s)
    for i in xrange(len(s)-n+1):
        for j in xrange(n):
            if not cs[i+j]:
                break
        else:
            m[i] = True
    def hasn(i, j):
        while i + n - 1 <= j:
            if m[i]: return True
            i += 1
        return False
    count = 0
    for i in xrange(len(s)):
        for j in xrange(i+n-1, len(s)):
            if hasn(i, j):
                count += 1
    return count
            

def main(filename):
    with open(filename) as f_in:
        total = int(f_in.readline())
        for i in xrange(1, total+1):
            s, n = f_in.readline().strip().split(' ')
            n = int(n)
            print 'Case #{0}: {1}'.format(i, solve(i, s, n))
            

if __name__ == "__main__":
    main(sys.argv[1])
