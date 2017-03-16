# import sys
fname = "B-small-attempt0.in"
# fname = "B-large.in"
# fname = "B-large-practice.in"
# fname = "sample.in"
fi = open(fname)
fo = open("fo.txt", "w")
for test in range(int(fi.readline())):
    a, b, k = [int(x) for x in fi.readline().strip().split()]
    print a, b, k
    count = 0
    for i in xrange(a):
        for j in xrange(b):
            if i & j < k:
                # print i, j, i & j
                count += 1
    print >>fo, "Case #%d: %d" % (test + 1, count)
