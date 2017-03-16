
#!/usr/bin/env python
import sys

stin = sys.stdin
stin.readline()

lines = stin.readlines()

for i,l in enumerate(lines):
    nums = map(int, l.split())
    n = nums[0]
    sx = nums[1:]
    
    print "Case #%d:" % (i+1),
    sm = reduce(lambda x,y: x+y , sx)
    q = 2.0*sm/len(sx)
    sf = filter(lambda x: x < q, sx)
    smf = reduce(lambda x,y: x+y, sf)
    for s in sx:
        if s < q:
            print " %.6f" % ((float(smf+sm)/len(sf) -s)/sm * 100),
        else:
            print " %.6f" % 0.0,
    print ""
