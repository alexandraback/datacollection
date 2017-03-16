inp = open("input.txt", "r")
outp = open("output.txt", "w")
e, r, n = 0, 0, 0
masv = [0] * 2
maxs = 0

def rec(nown, eo, nows):
    global e, r, n, maxs, masv
    if(nown == n):
        maxs = max(maxs, nows)
        return 0
    for i in xrange(eo + 1):
        rec(nown + 1, min(e, eo - i + r), nows + i * masv[nown])
    return 0    

t = int(inp.readline().strip())

for i in xrange(t):
    e, r, n = map(int, inp.readline().strip().split())
    masv = map(int, inp.readline().strip().split())
    maxs = 0
    rec(0, e, 0)
    outp.write("Case #" + str(i + 1) + ": " + str(maxs) + "\n")

inp.close()
outp.close()