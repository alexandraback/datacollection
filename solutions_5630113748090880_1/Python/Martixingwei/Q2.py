def solve(l):
    a = [0]*2501
    for i in l:
        a[i] += 1
    r = []
    for i in range(len(a)):
        if a[i]%2:
            r.append(str(i))
    return ' '.join(r)


filename = "B-large.in"
f = open(filename,"r")
fout = open(filename.replace(".in", ".out"), "w")
N = int(f.readline())
for i in range(N):
    n = int(f.readline().strip())
    l = []
    for j in range(2*n-1):
        l += [int(k) for k in f.readline().strip().split(' ')]
    res = solve(l)
    print("Case #{}:".format(i+1), res)
    print("Case #{}:".format(i+1), res,file=fout)
f.close()
fout.close()
