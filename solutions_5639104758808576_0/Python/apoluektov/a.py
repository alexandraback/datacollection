import sys

def line():
    return sys.stdin.readline().strip()

def ints(s):
    return [int(t) for t in s.split()]


def solve(ss):
    res = 0
    rem = 0
    for n in ss:
        if n == 0:
            if rem == 0:
                res += 1
            else:
                rem -= 1
        elif n == 1:
            pass
        else:
            rem += (n-1)
    return res

def main():
    tc = int(line())
    for i in range(1,tc+1):
        maxS, ss = line().split()
        ss = [int(c) for c in ss]
        print 'Case #%s: %s' % (i, solve(ss))



main()
