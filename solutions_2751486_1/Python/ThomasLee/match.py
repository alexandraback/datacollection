#!/usr/bin/env python

import re
count = int(raw_input())
vowels = re.compile("[aeiou]")
for case in xrange(1, count + 1):
    (word, lim) = raw_input().split()
    lim = int(lim)
    pos = [ m.start(0) for m in re.finditer(vowels, word) ]
    # i = word.find(vowels, 0)
    # while i != -1:
    #     pos.append(i)
    #     i = word.find(vowels, i + 1)

    pos.insert(0, -1)
    pos.append(len(word))
    cons =  map(lambda i: (pos[i]+1, pos[i+1]-pos[i]-1), xrange(0,len(pos) -1))
    fits = filter(lambda x: x[1] >= lim, cons)
    #print fits

    num = 0
    if len(fits) != 0:
        for i in xrange(0, len(word)):
            #print i
            if fits[0][0] - i + fits[0][1] < lim: fits.pop(0)
            #print fits
            if len(fits) == 0: break
            num += len(word) - (max(fits[0][0], i) + lim) + 1
            #print num

    print "Case #%d: %d" % (case, num)

        

