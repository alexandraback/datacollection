def getallparents(x, parents, direct):
    if parents[x] is not None:
        return parents[x]
    else:
        parents[x] = set(direct[x])
        parents[x].add(x)
        for j in direct[x]:
            parents[x].update(getallparents(j, parents, direct))
        return parents[x]

filename = raw_input("Enter the name of the input file: ")
f = open(filename, 'r')
outfile = open("outfile.txt", 'w')
t = int(f.readline())
for case in range(t):
    n = int(f.readline())
    outfile.write('Case #' + str(case + 1) + ': ')
    direct=[]
    parents = [None] * n
    for i in range(n):
        x = [int(i) - 1 for i in f.readline().split()]
        x.pop(0)
        direct.append(x)

    hasDiamond = False
    for i in range(n):
        if len(direct[i]) > 1:
            base = getallparents(direct[i][0], parents, direct).copy()
            for k in range(1, len(direct[i])):
                if not base.isdisjoint(getallparents(direct[i][k], parents, direct)):
                    hasDiamond = True
                    break
                else:
                    base.update(getallparents(direct[i][k], parents, direct))
            if hasDiamond:
                break
    if hasDiamond:
        outfile.write('Yes\n')
    else:
        outfile.write('No\n')
f.close()
outfile.close()
    

