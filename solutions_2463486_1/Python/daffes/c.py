import bisect

ncases = int(raw_input())

pal = []

def gen(l):
    if (len(l) > 8):
        return
    if (l and l[0] != '0'):
        i = int(''.join(l))
        ii = i*i
        if ispal(ii):
            pal.append(ii)
    for k in xrange(10):
        l.insert(0, chr(k+ord('0')))
        l.append(chr(k+ord('0')))
        gen(l)
        l.pop(0)
        l.pop(-1)

def ispal(i):
    return i == int(str(i)[::-1])

gen([])
for i in xrange(10):
    gen([chr(i+ord('0')),])
    
pal.sort()

for kk in xrange(ncases):
    print "Case #" + str(kk+1) + ":",
    a,b = map(int, raw_input().split(' '))
    print bisect.bisect_right(pal, b) - bisect.bisect_left(pal, a)

        
    
