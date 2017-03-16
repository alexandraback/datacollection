import sys

def solve():
    s = sys.stdin.readline().strip()
    ret = s[0]
    for l in s[1:]:
        if l < ret[0]:
            ret += l
        else:
            ret = l + ret

    return ret

if __name__ == '__main__':
    c = int(sys.stdin.readline())
    for i in xrange(c):
        print 'Case #%s: %s' % (i + 1, solve())
