import sys

f = open(sys.argv[1])
f.readline()
t = 1
for l in f:
    nrow,ncol,w = [int(x) for x in l.split()]
    output = ncol/w * nrow - 1 + w
    if ncol % w:
        output += 1

    print "Case #{}: {}".format(t,output)
    t += 1
f.close()
