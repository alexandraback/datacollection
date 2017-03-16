import sys
import bisect
import math

def is_palindrome(n):
    s = str(n)
    return s == s[::-1]

roots = []
for n in xrange(1, 10 ** 7 + 1):
    if is_palindrome(n) and is_palindrome(n ** 2):
        roots.append(n)
        
def solve(A, B):
    a = bisect.bisect_left(roots, math.sqrt(A))
    b = bisect.bisect_right(roots, math.sqrt(B))
    return b - a

def main():
    T = int(sys.stdin.readline())
    for t in range(T):
        A, B = map(int, sys.stdin.readline().rstrip().split())
        result = solve(A, B)
        print "Case #%d: %s" % (t + 1, result)
    
if __name__ == '__main__':
    main()
