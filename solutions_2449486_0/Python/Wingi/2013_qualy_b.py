import sys

def solve(n, m, lines):
    #find max value per row
    nMax = map(max, lines)

    #find max value per column
    mMax = lines[0][:]   # copy array, not "mMax = lines[0]"
    for i in range(1, n):
        for j in range(m):
            mMax[j] = max(mMax[j], lines[i][j])

    #test for every square, A(n,m) >= the colMax or rowMax
    for i in range(n):
        for j in range(m):
            if lines[i][j]>=nMax[i] or lines[i][j]>=mMax[j]:
                pass
            else:
                return "NO"
    return "YES"
                   

IN = file(sys.argv[1])

for t in range(1, int(IN.readline())+1):
    n,m = map(int, IN.readline().split(" "))
    lines = [map(int, IN.readline().split(" ")) for x in range(n)]
    print "Case #%d: %s" % (t, solve(n, m, lines))
