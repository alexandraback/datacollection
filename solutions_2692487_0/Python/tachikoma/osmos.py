import sys

def steps_impl(A, data, s, sup):
    while data and A > data[0]:
        A += data.pop(0)
    left = len(data)
    if left == 0:
        return s
    s += 1
    if left == 1 or s == sup:
        return s
    A = 2 * A - 1
    return steps_impl(A, data, s, min(s + left - 1, sup))

def steps(A, data):
    data.sort()
    return steps_impl(A, data, 0, len(data))

f = open(sys.argv[1])
T = int(f.readline())
for t in xrange(1,T+1):
    A, N = map(int, f.readline().strip().split())
    data = map(int, f.readline().strip().split())
    print "Case #{0}: {1}".format(t, steps(A, data))
