import math

def solve(A):
    n = len(A)
    A.sort()
    S = sum(A)
    l = 0
    #print A
    res = S
    for i, a in enumerate(A):
        l += A[i-1] if i > 0 else 0
        r = S - a - l
        # print l, a, r, "=>", a * i - l, r - a * (n - i - 1), a * i - l + r - a * (n - i - 1)
        res = min(res, a * i - l + r - a * (n - i - 1))
    # print A, res
    return res


def CASE(IN):
    def rstr():
        return IN.readline().strip()
    
    Ns, A = rstr().split()
    Smax = int(Ns)
    num_friends = 0
    running_sum = int(A[0])
    #print "Smax, A, running_sum", Smax, A, running_sum
    i = 1
    while i <= Smax:
        if int(A[i]) != 0:
            if (i - running_sum) > 0:
                num_friends += (i - running_sum)
                running_sum = i 
        running_sum += int(A[i])
        i += 1
    #print "friends = ", num_friends
    return str(num_friends)


def RUN(IN, OUT):
    t = int(IN.readline().strip())
    for i in xrange(1, t + 1):
        OUT.write("Case #%i: %s\n" % (i, CASE(IN)))

if __name__ == "__main__":
    import sys
    RUN(sys.stdin, sys.stdout)
