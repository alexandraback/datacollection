import bisect
from sys import stdin

def is_palindrome(x):
    s = str(x)
    return s[::-1] == s

# Precompute up to 100 digits
pspr = [[''], ['0', '1', '2', '3']]
fas = [1, 4, 9]
for n in range(2,51):
    rv = []
    for zeros in range(n/2):
        lencore = n - 2*(zeros+1)
        for core in pspr[lencore]:
            for d in ['1','2']:
                test = d + '0'*zeros + core + '0'*zeros + d
                num = int(test)
                sq = num * num
                if is_palindrome(sq):
                    rv.append(test)
                    fas.append(sq)
    rv.sort()
    pspr.append(rv)

fas.sort()

C = int(stdin.readline())
for x in range(C):
    (lo, hi) = [int(X) for X in stdin.readline().split()]
    l = bisect.bisect_left(fas, lo)
    r = bisect.bisect_right(fas, hi)
    print "Case #" + str(x+1) + ": " + str(r-l)


