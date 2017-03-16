#~ f = open('0c.in')
f = open('C-small-attempt0.in')

T = int(f.readline().strip())
for case in range(T):
    A, B = [int(x) for x in f.readline().strip().split()]
    result = 0
    found = set()
    for a in range(A, B+1):
        achars = str(a)
        for i in range(1, len(achars)):
            b = int(achars[i:] + achars[:i])
            if b <= B and b > a and not (a, b) in found:
                found.add((a, b))
                result += 1
    print "Case #%s: %s" % (case + 1, result)
