# Google Code Jam 2013, Round 1B, Problem A
#


import sys, re

def fib(k, n):
    '''(How many times must k_i+1 = k_i + k_i-1 be evaluated
    to be larger than n, and whats the value)'''
    i = 0
    while k <= n:
        k += k - 1
        i += 1
    return (i, k)
    

def solve(num, a, n, ms):
    if a <= 1:
        return len(ms)
    ms = sorted(ms)
    c = 0
    i = 0
    sols = []
    while i < len(ms):
        m = ms[i]
        if m < a:
            # eat
            a += m
        else:
            j, k = fib(a, m)
            assert k > m
            a = k + m
            sols.append(c + len(ms) - i)
            c += j
        i += 1
    sols.append(c)
    return min(sols)
        
            

def main(filename):
    with open(filename) as f_in:
        total = int(f_in.readline())
        for i in xrange(1, total+1):
            a, n = map(int, f_in.readline().strip().split(' '))
            ms = map(int, f_in.readline().strip().split(' '))
            print 'Case #{0}: {1}'.format(i, solve(i, a, n, ms))
            

if __name__ == "__main__":
    main(sys.argv[1])
