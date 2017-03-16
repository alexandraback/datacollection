lines = open('C.in').readlines()
lines = lines[1:]

for idx, line in enumerate(lines):
    blah = []
    count = 0
    A, B = map(int, line.split(' '))
    sf = len(str(A)) - 1
    for i in xrange(A, B+1):
        _t = i
        for j in xrange(0, sf):
            _t = _t / 10 + (_t % 10) * 10 ** sf
            if _t == i:
                break
            if _t <= B and _t > i:
                count += 1
    print "Case #%d: %d" % (idx + 1, count)
