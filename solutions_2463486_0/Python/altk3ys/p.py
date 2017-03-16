fsq = 0,1,4,9,121,484,10201
rd = raw_input
for t in range(1,1+int(rd())):
    a,b=map(int,rd().split())
    print 'Case #%d: %d' % (t, len([f for f in fsq if f>=a and f<=b]))
