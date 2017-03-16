#!/usr/bin/python

from __future__ import division
from gcj import *

# boolean flags, reachable via OPTS.flagname. Space separated in string
FLAGS = ''

MAXREM = 1000

def initlib():
    LIB.frombase.restype = ctypes.c_int64

def case():
    N, J = ints()
    num = 10**(N-1) + 1
    print num
    base2rem = [None] * 11
    for base in range(2, 11):
        n10 = int(str(num), base)
        print "In base %d, %d is %d" % (base, num, n10)
        rem = base2rem[base] = [None, None]
        for i in range(2, MAXREM):
            rem.append(n10 % i)
    got = 0
    out('')
    for i in xrange(1<<(N-2)):
        proves = []
        for base in range(2, 11):
            rem = base2rem[base]
            mid = LIB.frombase(i, base)
            #print i, bin(i), base, LIB.frombase(i, base)
            tail = mid*base
            for j in range(2, MAXREM):
                val = rem[j] + tail
                if (rem[j] + tail) % j == 0:
                    proves.append(j)
                    break
            else:
                break
        else:
            # Success
            mynum = num + LIB.frombase(i, 10)*10
            print "Verifying %d..." % mynum
            for base in range(2, 11):
                inb = int(str(mynum), base)
                p = proves[base-2]
                r = inb%p
                print "- %d %% %d = %d" % (inb, p, r)
                if r or not (1 < p < inb):
                    raise Exception("Aiee")
            out(' '.join(map(str, [mynum] + proves)))
            got += 1
            if got == J:
                break
    else:
        print "Could not find enough..."

if __name__ == '__main__':
    main()
