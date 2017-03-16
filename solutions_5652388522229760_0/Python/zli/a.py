def xl(l):
    return xrange(len(l))

for case in range(input()):
    print "Case #%s:" % (case+1),
    N = input()
    if N == 0:
        print "INSOMNIA"
        continue
    digits = set()
    i = 1
    while True:
        #print digits
        digits = digits.union(set(str(i*N)))
        if len(digits) == 10:
            break
        i += 1
    print i*N
