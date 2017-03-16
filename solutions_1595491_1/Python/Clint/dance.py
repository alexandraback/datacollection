from sys import argv
script, file_name = argv

in_file = open(file_name, 'r')

for i in range(int(in_file.readline())):
    t = [int(j) for j in in_file.readline().split(' ')]
    n = t.pop(0)
    s = t.pop(0)
    p = t.pop(0)
    m = 0
    for ti in t:
        q = ti / 3
        if ti % 3 > 0: q += 1
        if q >= p: m += 1
        elif s > 0:
            if ti > 0 and ti % 3 != 1: q += 1
            if q >= p:
                m += 1
                s -= 1
    print "Case #%d: %d" % (i+1, m)

in_file.close()
