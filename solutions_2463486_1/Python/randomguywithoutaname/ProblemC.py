import math

def isPalindrome(s):
    strS = str(s)
    return strS == strS[::-1]

def preCompute():
    l = []
    for i in range(1, 10000):
        s = str(i)
        pal1, pal2 = s+s[::-1], s[:-1]+s[::-1]
        n1, n2 = int(pal1)**2, int(pal2)**2
        if isPalindrome(n1):
            l.append(n1)
        if isPalindrome(n2):
            l.append(n2)
    l.sort()
    return l

def probC(n, fns):
    cnt = 0
    for i in range(0, n):
        A, B = tuple(int(n) for n in input().split())
        a, b = 0, 0
        while (a < len(fns) and A > fns[a]):
            a += 1
        while (b < len(fns) and B >= fns[b]):
            b += 1
        print("Case #%d: %d" % (i+1, b - a))
        
fns = preCompute()
n = int(input())
probC(n, fns)
