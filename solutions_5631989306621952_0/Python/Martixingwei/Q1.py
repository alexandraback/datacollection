def solve(s):
    if len(s)==1:
        return s
    r = solve(s[:-1])
    if s[-1]>=r[0]:
        return s[-1]+r
    else:
        return r+s[-1]

filename = "A-small-attempt0.in"
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
