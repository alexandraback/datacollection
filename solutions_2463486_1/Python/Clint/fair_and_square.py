import math

def isPalindrome(num):
    if num % 10 == 0: return False
    return str(num) == str(num)[::-1]    


palindrome = []
limit = pow(10, 14)
sqrt_limit = int(math.sqrt(limit))+1

for n in range(1, sqrt_limit):
    if isPalindrome(n): palindrome.append(n)

square = []
for n in palindrome:
    m = n*n
    if isPalindrome(m):
        if m <= limit: square.append(m)

for t in range(int(raw_input())):
    d = [int(j) for j in raw_input().split(' ')]
    a, b = d[0], d[1]
            
    print "Case #%d: %d" % (t+1, sum(1 for n in square if n >= a and n <= b))
