import sys

args = sys.argv
file = args[1]
f = open(file)

cases = int(f.readline())

for i in range(cases):
    l = f.readline().split(' ')
    r = int(l[0])
    c = int(l[1])
    w = int(l[2])
    n = c / w
    if c % w == 0:
        a = w - 1
    else:
        a = w
    print "Case #%s: %s" % (i + 1,(n + a)*r)
    
