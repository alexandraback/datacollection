#!/usr/bin/python2

import math

f = open("/home/vadim/Downloads/a.txt", "r")
n = int(f.readline())
out = open("/home/vadim/Downloads/b.txt", "w")

for cs in xrange(n):
    out.write("Case #" + str(cs + 1) + ": ")
    line = f.readline()
    R = int(line.split()[0])
    T = int(line.split()[1])

    g = 0
    k = T
    while 1:
        z = (g+k) / 2
        if T >= (2*z*z + z*(2*R-1)):
            if T < (2*(z+1)*(z+1) + (z+1)*(2*R-1)):
                k = z
                break
            else:
                g = z
        else:
            k = z

    print(k)
    out.write(str(k) + "\n")

f.close()
out.close()
