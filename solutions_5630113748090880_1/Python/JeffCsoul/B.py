fin = open("B-large.in","r")
fout = open("ans_L.txt","w")

T = eval(fin.readline())
for T_T in range(T):
    d = dict()
    n = eval(fin.readline())
    for i in range(2 * n - 1):
        st = fin.readline().strip().split(' ')
        for x in st:
            temp = eval(x)
            if temp in d:
                d[temp] += 1
            else:
                d[temp] = 1
    ans = list()
    for x in d:
        if d[x] % 2 == 1:
            ans.append(x)
    ans = sorted(ans)
    fout.write("Case #" + str(T_T + 1) + ":")
    for x in ans:
        fout.write(" " + str(x))
    fout.write("\n")