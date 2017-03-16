inputfile = file("A-small-attempt0.in", "rb")
outputfile = file("A-small.out", "wb")
out_s = "Case #%d: %d"
parse_line = lambda: [int(a) for a in inputfile.readline().split()]

def int_sqrt(n):
    k = n/2
    k_new = n/2 + 1
    while k_new != k:
        k = k_new
        k_new = ( k + n/k )/2
        if k**2 < n < (k+1)**2:
            break
    return k

T = int(inputfile.readline())
for ncase in xrange(1,T+1):
    from math import sqrt, floor
    r, t = parse_line()
    delta = 4*r*r-4*r+1+8*t
    n = ( ((1-2*r) + int_sqrt(delta)) / 4 )
    n_inted = int(n)
    print >>outputfile, out_s % (ncase, n_inted)

