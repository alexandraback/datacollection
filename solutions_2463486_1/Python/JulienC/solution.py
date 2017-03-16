from math import sqrt, ceil

def is_palyndrome(number):
    nStr = str(number)
    half = len(nStr) / 2
    for i in xrange(half):
        if nStr[i] != nStr[-1-i]:
            return False
    return True

def solve(A, B):
    lower = int(sqrt(A))
    upper = int(ceil(sqrt(B)))
    count = 0
    n = lower
    while n <= upper:
        if n*n < A or n*n > B:
            n += 1
            continue
        if is_palyndrome(n) and is_palyndrome(n*n):
            count += 1
        n += 1
    return count

T = int(input())
for t in range(T):
    A,B = [int(s) for s in raw_input().split()]
    print 'Case #' + str(t+1) + ': ' + str(solve(A, B))


