def solve(s):
    return sum([s[i]!=s[i+1] for i in range(len(s)-1)]) + (s[-1]=='-')

numCases = input()
for i in range(1,numCases+1):
    s = raw_input()
    print "Case #%d: %d" % (i, solve(s))

