import sys

f = open(sys.argv[1])

T = int(f.readline())

#s = 0
#for i in range(10):
#    x = s + i*4 + 1
#    print x,
#    s += x

for tc in range(T):
    r, t = [int(v) for v in f.readline().split()]
    count = 0
    used = 0
    while used <= t:
        need = 2*r + count*4 + 1
        #print 'Used:', used, 'circles', count
        if used + need > t:
            break
        count += 1
        used += need
    print 'Case #%s: %s' % (tc+1, count)
