import sys

f = open(sys.argv[1])

T = int(f.readline())

def get_sum(r, n):
    return n*(2*r+2*n-1)


for tc in range(T):
    r, t = [int(v) for v in f.readline().split()]
    #print 'r', r, 't', t
    n1 = 0
    n2 = t
    while n1 < n2:
        #print n1, n2
        if n2-n1 == 1:
            break
        n = (n2 + n1)/2
        s = get_sum(r, n)
        if s > t:
            n2 = n
        elif s < t:
            n1 = n
        else:
            n1 = n
            break

    print 'Case #%s: %s' % (tc+1, n1)
    #raw_input()
