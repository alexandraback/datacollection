pnum = 0
p = []

def s(size,i):
    
    if i >= pnum:
        return 0
    if size > p[i]:
        return s(size + p[i], i+1)
    if size < 2:
        return s(size, i+1) + 1
    eatnum = 0
    size2 = size
    while size2 <= p[i]:
        size2 = size2 * 2 - 1
        eatnum += 1
    eat = s(size2 + p[i], i+1) + eatnum
    skip = s(size, i+1) + 1
    return min([eat, skip])

testnum = int(raw_input())
for test in xrange(1,testnum+1):
    eater, pnum = map(int,raw_input().strip().split())
    p = map(int,raw_input().strip().split())
    p.sort()
    print "Case #%d: %d" % (test, s(eater, 0))