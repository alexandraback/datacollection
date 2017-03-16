import sys
import math

def ispalindrome(x):
    v = str(x) 
    return int(v == v[::-1])

def solve(start, end):
    s = int(math.ceil(math.sqrt(start)))
    e = int(math.floor(math.sqrt(end)))
    count = 0
    print "scanning", s, e
    for i in xrange(s, e+1):
        v = ispalindrome(i) and ispalindrome(i*i)
        if (v):
            print i, i * i
            count += 1
    return count

def main():
    count = int(sys.stdin.readline())
    for i in range(count):
        start, end = [int(v) for v in sys.stdin.readline().strip().split()]
        print "Case #%d: %d" % (i + 1, solve(start, end))

main()
