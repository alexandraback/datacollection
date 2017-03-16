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

def findPos(arr, num):
    low = 0
    up = len(arr)
    while low < up:
        mid = (low+up) / 2
        if arr[mid] < num:
            low = mid+1
        elif arr[mid] > num:
            up = mid
        else:
            return mid
    return up-1

T = int(sys.stdin.readline())
low = 1
up = 10000000
cnt = 0
fairsquare = []
for i in xrange(low, up+1):
    if isPalindrome(i):
        sq = i*i
        if isPalindrome(sq):
            #print sq
            fairsquare.append(sq)
            cnt += 1
#print fairsquare

for ca in xrange(1, T+1):
    [A, B] = [int(v) for v in sys.stdin.readline().split(" ")]
    pA = findPos(fairsquare, A-1)
    pB = findPos(fairsquare, B)
    print "Case #%d: %d" % (ca, pB-pA)
    
