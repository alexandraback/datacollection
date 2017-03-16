import sys

if len(sys.argv) == 1:
    inp = sys.stdin
else:
    inp = open(sys.argv[1])
for x in xrange(int(inp.readline())):
    C, F, X = map(float, inp.readline().split(' '))
    time, farms, pttw, ttw = 0, 0, 0, 0
    while True:
        pttw = ttw
        ttw = time + X / (F * farms + 2)
        if pttw > 0 and pttw < ttw:
            break
        time += C / (F * farms + 2)
        farms += 1
    print 'Case #%d: %.7f' % (x+1, pttw)
inp.close()
