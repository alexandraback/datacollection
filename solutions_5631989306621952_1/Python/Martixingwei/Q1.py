def solve(s):
    r = s[0]
    for i in s[1:]:
        if i>=r[0]:
            r = i+r
        else:
            r = r+i
    return r


filename = "A-large.in"
f = open(filename,"r")
fout = open(filename.replace(".in", ".out"), "w")
N = int(f.readline())
for i in range(N):
    s = f.readline().strip()
    res = solve(s)
    print("Case #{}:".format(i+1), res)
    print("Case #{}:".format(i+1), res,file=fout)
f.close()
fout.close()
