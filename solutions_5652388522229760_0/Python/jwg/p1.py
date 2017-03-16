def solve(n):
    if n == 0:
        return "INSOMNIA"
    s1 = set()
    nn = n
    for i in range(1, 10000):
        s1.update(set(str(nn)))
        if len(s1)==10:
            return nn
        nn += n
       
numCases = input()
for i in range(numCases):
        n = input()
        print "CASE #%d: %s" % (i+1, str(solve(n)))

