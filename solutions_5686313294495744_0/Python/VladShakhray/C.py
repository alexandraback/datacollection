fin = open("input.txt", 'r')
fout = open("output.txt", 'w')
t = int(fin.readline())

for test in range(1, t + 1):
    n = int(fin.readline())
    print(n)
    carthages = []
    d = dict()
    for i in range(n):
        a, b = fin.readline().split()
        dk1 = 2*i
        dk2 = 2*i+1
        if a in d.keys():
            dk1 = d[a]
        if b in d.keys():
            dk2 = d[b]
        d[a] = dk1
        d[b] = dk2
        carthages.append((dk1, dk2))
    print(carthages)
    carthages = sorted(carthages, key=lambda x: (-x[1], x[0]))
    sum = 0
    for k in range(n-1, -1, -1):
        rem = carthages[k]
        _1 = False
        _2 = False
        for i in range(k):
            if carthages[i][0] == rem[0]:
                _1 = True
        for i in range(k):
            if carthages[i][1] == rem[1]:
                _2 = True
        if _1 and _2:
            sum+=1
    fout.write("Case #" + str(test) + ': ' + str(sum) + '\n')

fin.close()
fout.close()
