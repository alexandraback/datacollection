from math import sqrt, ceil

def is_palyndrome(number):
    nStr = str(number)
    half = len(nStr) / 2
    for i in range(half):
        if nStr[i] != nStr[-1-i]:
            return False
    return True

def solve(A, B):
    lower = int(sqrt(A))
    upper = int(ceil(sqrt(B)))
    count = 0
    for n in range(lower, upper+1):
        if n*n < A:
            continue
        if n*n > B:
            continue
        if is_palyndrome(n) and is_palyndrome(n*n):
            count += 1
    return count

T = int(input())
for t in range(T):
    A,B = [int(s) for s in raw_input().split()]
    print 'Case #' + str(t+1) + ': ' + str(solve(A, B))


