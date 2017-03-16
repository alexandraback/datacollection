for cas in xrange(int(raw_input())):
    r, c, w = map(int, raw_input().split())
    print "Case #{0}: {1}".format(cas+1, c/w+w-1+(c%w!=0))
