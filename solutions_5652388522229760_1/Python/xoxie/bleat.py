import sys

f = open(sys.argv[1])
f.readline()
casenum = 1
for l in f:
    i = int(l)
    if i == 0:
        output = "INSOMNIA"
    else:
        n = i
        nums = set(str(n))
        while len(nums) < 10:
            n += i
            nums |= set(str(n))
        output = n
    print "Case #{}: {}".format(casenum,output)
    casenum += 1
f.close()
