def ints():
    return map(int, raw_input().split())

N = 10 ** 6 + 3
A = [0] * N

def reverse(n):
    s = str(n)
    return int(s[::-1])

A[1] = 1
for n in range(2, N):
    A[n] = A[n-1] + 1
    if n % 10:
        m = reverse(n)
        if m < n:
            A[n] = min(A[n], A[m] + 1)


num_cases, = ints()

for case_num in xrange(1, num_cases + 1):
    n, = ints()
    print "Case #%d: %d" % (case_num, A[n])
