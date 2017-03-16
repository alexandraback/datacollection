import sys

f = open(sys.argv[1])
f.readline()

casenum = 1
for l in f:
    stack = [int(x) for x in l.strip().replace("+","1").replace("-","0")]
    
    output = 0
    i = len(stack)-1
    while i >= 0:
        if stack[i]:
            i -= 1
        else:
            stack = [not x for x in stack[:i]]
            i -= 1
            output += 1
    print "Case #{}: {}".format(casenum,output)
    casenum += 1
f.close()
