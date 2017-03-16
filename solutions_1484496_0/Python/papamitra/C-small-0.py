
#!/usr/bin/env python
import sys
import itertools

stin = sys.stdin
stin.readline()

lines = stin.readlines()

for i,l in enumerate(lines):
    nums = map(int, l.split())
    n = nums[0]
    sx = nums[1:]

    tbl = {}
    flg = False
    for l in range(len(sx)):
        if flg: break
        for c in itertools.combinations(sx,l+1):
            sm = sum(c)
            if tbl.has_key(sm):
                print "Case #%d:" % (i+1)
                print " ".join(map(str, c))
                print " ".join(map(str, tbl[sm]))
                flg = True
                break
            else:
                tbl[sm] = c
    else:
        print "Case #%d:" % (i+1)
        print "Impossible"
