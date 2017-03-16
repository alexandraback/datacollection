def ints():
    return map(int, raw_input().split())

N = 10 ** 6 + 3

#A = [0] * N
#prec = [0] * N
#
#def reverse(n):
#    s = str(n)
#    return int(s[::-1])
#
#A[1] = 1
#for n in range(2, N):
#    A[n] = A[n-1] + 1
#    prec[n] = n-1
#    if n % 10:
#        m = reverse(n)
#        if m < n:
#            A[n] = min(A[n], A[m] + 1)
#            if A[n] <= A[n-1]:
#                prec[n] = m

#x = N-1
#while x:
#    print x
#    x = prec[x]

def solve(n):
    s = str(n)
    if s.endswith('0'):
        return 1 + solve(n-1)
    L = len(s)
    if L == 1:
        return n
    a = s[:L/2][::-1]
    b = s[L/2:]
    return int(a) + int(b) + (1 if int(a) > 1 else 0) + solve(10 ** (L-1) - 1)

#for i in range(1, N):
#    if A[i] != solve(i):
#        print i, A[i], solve(i)

num_cases, = ints()
for case_num in xrange(1, num_cases + 1):
    n, = ints()
    print "Case #%d: %d" % (case_num, solve(n))
