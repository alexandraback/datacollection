import math

ac = [0]*(1 + 10**7)

def palindrome(i):
    s = str(i)
    return (s == s[::-1])

n = 0

for i in range(1, 1 + 10**7):
    if palindrome(i) and palindrome(i*i):
         n += 1
        
    ac[i] = n;

t = int(raw_input())

for c in range(1, t + 1):
    a, b = map(int, raw_input().split())

    print "Case #" + str(c) + ": " + str((ac[int(math.sqrt(b))] -  ac[int(math.ceil(math.sqrt(a))) - 1]))
