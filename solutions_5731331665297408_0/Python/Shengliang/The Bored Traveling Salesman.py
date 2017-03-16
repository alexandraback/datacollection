dataMap = []
visited = []
zipCode = []
ans = ""

def sss(x):
    global ans
    #print x
    temp = dataMap[x]
    #print temp
    flag = True
    while flag:
        flag = False
        next = 0
        mmin = "z"
        for j in temp:
            if not visited[j] and mmin > zipCode[j]:
                next = j
                mmin = zipCode[j]
        if mmin != "z":
            ans = ans + str(zipCode[next])
            visited[next] = True
            sss(next)
            flag = True
        
    

def main():
    fin = file("C-small-attempt0.in","r")
    t = int(fin.readline())
    fout = file("C.out", "w")
    for i in range(t):
        scanf = fin.readline().split()
        n = int(scanf[0])
        m = int(scanf[1])
        global zipCode
        zipCode = []
        for j in range(n):
            st = fin.readline()
            zipCode.append(st[0:len(st)-1])
        global dataMap
        dataMap = []
        global visited
        visited = []
        global ans
        ans = ""
        for j in range(n):
            a = []
            dataMap.append(a)
            visited.append(False)
        
        for j in range(m):
            scanf = fin.readline().split()
            x = int(scanf[0]) - 1;
            y = int(scanf[1]) - 1;
            dataMap[x].append(y)
            dataMap[y].append(x)
        start = zipCode.index(min(zipCode))
        print start
        visited[start] = True
        ans = zipCode[start]
        sss(start)
        output = 'Case #' + str(i+1) + ": " + ans + '\n'
        fout.write(output)


if __name__ == '__main__':
    main()
