# coding: utf8

def scan():
    while True:
        for w in raw_input().split():
            yield w

words = scan()

def scans(num=-1):
    return (next(words) for i in xrange(num)) if num >= 0 else next(words)

def scani(num=-1):
    return (int(value) for value in scans(num)) if num >= 0 else int(scans())

#------------------------------------------------------------------------------
for case in xrange(1, scani() + 1):
    print "Case #%d:" % (case,),
    a, b= scans(2)
    count = 0
    for value in xrange(int(a), int(b) + 1):
        n = str(value)
        l = []
        for pos in xrange(1, len(n)):
            m = n[pos:] + n[:pos]
            if a <= n < m <= b:
                l.append(m)
        count += len(set(l))
    print count
