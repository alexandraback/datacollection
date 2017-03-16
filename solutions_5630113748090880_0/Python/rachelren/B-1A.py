def findMissing(l):
    m = dict()
    for i in l:
        if m.has_key(i):
            m[i] += 1
        else:
            m[i] = 1

    result = []
    key = m.keys()

    for k in key:
        if m[k] % 2 != 0:
            result.append(k)
    r = ""
    result.sort()
    for i in result:
        r += str(i) + " "
    return r[:-1]


# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
    n = int(raw_input())
    l = []
    for row in xrange(2 * n - 1):
        l += [int(s) for s in raw_input().split(" ")]  # read a list of integers, 2 in this case
    r = findMissing(l)
    print "Case #" + str(i) +": " + r
    # print "Case #{}: {}".format(i,1)
    # check out .format's specification for more formatting options