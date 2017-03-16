import sys
import math

def isPalindrome(n):
    digits = []
    while n > 0:
        digits.append(n%10)
        n /= 10
    ndigit = len(digits)
    for i in range(ndigit/2):
        if digits[i] != digits[ndigit-i-1]:
            return False
    return True
    

T = int(sys.stdin.readline())
for ca in xrange(1, T+1):
    [A, B] = [int(v) for v in sys.stdin.readline().split(" ")]
    #print lawn
    low = int(math.sqrt(A-1))
    up = int(math.sqrt(B+10))
    while low*low < A:
        low += 1
    while up*up > B:
        up -= 1
    cnt = 0
    for i in xrange(low, up+1):
        if isPalindrome(i):
            sq = i*i
            if isPalindrome(sq):
                #print sq
                cnt += 1
    
    print "Case #%d: %d" % (ca, cnt)
    
