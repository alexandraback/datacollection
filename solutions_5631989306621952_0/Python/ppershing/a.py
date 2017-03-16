import sys

def solve(testcase):
    x = sys.stdin.readline().strip()
    s = x[0]
    m = x[0]
    for y in x[1:]:
        if y >= m:
            s = y + s
            m = y
        else:
            s = s + y
    print "Case #%d: %s" % (testcase, s)

for t in range(int(sys.stdin.readline().strip())):
    solve(t+1)
