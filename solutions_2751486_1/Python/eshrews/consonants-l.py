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

    valids = [] 

    result = 0
    count = 0
    for i, c in enumerate(s):
        if c in vowelset:
            count = 0
        else:
            count += 1
        if count >= n:
            valids.append(i-n+1)

    validsi = 0
    result = 0
    for i in xrange(len(s)):
        if(validsi == len(valids)):
            break

        result += len(s) - n - valids[validsi] + 1

        if i == valids[validsi]:
            validsi += 1
        

    print "Case #{0}: {1}".format(linenum, result)
