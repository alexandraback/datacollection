import sys
scan = sys.stdin.read().split().__iter__().next

def work():
    r, t = int(scan()), int(scan())
    L = 0
    R = 10**18
    while L+1 < R:
        M = (L+R) /2
        if (M-r+1)*(M+r) > 2*t:
            R = M
        else:
            L = M
    return (L-r+1)/2

def main():
    z = int(scan())
    for i in xrange(1,z+1):
        print "Case #%d: %d"% (i, work())

main()
