fin = open("../Downloads/A-large.in")
fout = open("a.out", 'w')
def main(a):
    t, string = fin.readline().rstrip().split()
    t = int(t)
    string = list(map(int, list(string)))
    aw = 0
    j = 0
    for i in range(t + 1):
        if aw >= i:
            #print(1)
            aw += string[i]
        else:
            #print(2)
            j += 1
            aw += 1 + string[i]
    print("Case #%d: %d"%(a, j), file=fout)


n = int(fin.readline().rstrip())
for i in range(n):
    main(i + 1)
fout.close()