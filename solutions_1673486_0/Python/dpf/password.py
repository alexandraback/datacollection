import sys
def probs (p_array):
    acc = 1
    a_array = []
    for p in p_array:
        acc *= p
        a_array.append(acc)
    return a_array

def foo (a, b, ps):
    a_s = [1] + probs(ps)
    remaining_keys = (b - a) + 1
    retyping_keys = b + 1
    min_expected = 0
    if (a < b):
        min_expected = retyping_keys + 1
    #print min_expected
    for i, p in enumerate(a_s):
        backspace_keys = 2 * (a-i)
        #print remaining_keys + backspace_keys, remaining_keys + backspace_keys + retyping_keys
        expected = (remaining_keys + backspace_keys) * p + (remaining_keys + backspace_keys + retyping_keys) * (1-p)
        #print expected
        min_expected = min(expected, min_expected)
    # enter now
    #min_expected = min_expected(
    return min_expected


n = int(sys.stdin.readline())
for i in xrange(1, n+1):
    line = sys.stdin.readline()
    ints = [int(j) for j in line.split()]
    line = sys.stdin.readline()
    reals = [float(j) for j in line.split()]
    y = foo(ints[0], ints[1], reals)
    print "Case #"+str(i)+": "+str(y)

