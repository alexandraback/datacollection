def f(a, m, o, p):
    #if p: print a, m, o
    if not len(m): return o
    if a == 1: return len(m)
    if a > m[0]: return f(a+m[0], m[1:], o, p)
    #if p: print "wat", o, f(2*a-1,m,o+1, False),len(m)
    return min(f(2*a-1,m,o+1, p),o+len(m))

t = int(raw_input())
T = 1
while T <= t:
    a, n = [int(i) for i in raw_input().split()]
    m = sorted([int(i) for i in raw_input().split()])
    print "Case #{0}: {1}".format(T, f(a, m, 0, True))
    T += 1
