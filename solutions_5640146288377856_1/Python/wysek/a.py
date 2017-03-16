def solve():
    R, C, W = [int(x) for x in raw_input().split()]
    res = 0
    res = (R-1) * (C/W)
    res += C/W
    res += W-1
    res += 1 if C%W != 0 else 0
    return res

def main():
    T = int(raw_input())
    for t in xrange(1, T+1):
        print "Case #%d: %d" % (t, solve())

if __name__ == '__main__':
    main()

