lines = open('C.in').readlines()
lines = lines[1:]

def sot(a, b):
    if a[0] - b[0] != 0:
        return a[0] - b[0]
    else:
        return a[1] - b[1]

for idx, line in enumerate(lines):
    blah = []
    count = 0
    A, B = map(int, line.split(' '))
    for i in xrange(A, B+1):
        s = str(i)
        for j in xrange(1, len(s)):
            t = s[j:] + s[0:j]
            _t = int(t)
            if _t == i:
                break
            if _t <= B and _t > i:
                count += 1
    print "Case #%d: %d" % (idx + 1, count)
