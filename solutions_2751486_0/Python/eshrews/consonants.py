#!/usr/bin/python

import fileinput

vowelset = set(['a','e','i','o','u'])

case = 1
for linenum, line in enumerate(fileinput.input()):
    if linenum == 0:
        cases = int(line)
        continue

    
    ll = line.split()
    s = ll[0]
    n = int(ll[1])

    result = 0
    for i in xrange(len(s)):
        for j in xrange(i+1, len(s)+1):
            subs = s[i:j]
            count = 0
            for sc in subs:
                if sc in vowelset:
                    count = 0
                else:
                    count += 1
                if count == n:
                    result += 1
                    break
                

    print "Case #{0}: {1}".format(linenum, result)

