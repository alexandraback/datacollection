fin = open("A-large.in","r")
fout = open("ans_L.txt","w")

n = eval(fin.readline())
for T in range(n):
    st = fin.readline().strip()
    ans = str()
    for x in st:
        if (x + ans) > (ans + x):
            ans = x + ans
        else:
            ans = ans + x
    fout.write("Case #" + str(T + 1) + ": " + ans + '\n')