
fi = open("data.in")
T = int(fi.readline())
for I in range(1, T+1):
    w = fi.readline()
    n = int(w)
    s = fi.readline()[:-1].split(' ')
    oc = [0 for x in range(26)]
    for i in s:
        for j in i:
            oc[ord(j)-97] += 1
    bl = True
    for i in s:
        if i[0] == i[-1]:
            for j in i[1:-1]:
                if j != i[0]:
                    bl = False
        else:
            st, ed = 1, len(i)-2
            while i[st] == i[0]: st += 1
            while i[ed] == i[-1]: ed -= 1
            st, ed = st - 1, ed + 1
            for j in i[st+1:ed]:
                if oc[ord(j)-97] != 1:
                    bl = False
    if not bl:
        print "Case #%d: 0"%I
    else:
        a = [-1 for x in range(26)]
        b = [-1 for x in range(26)]
        f = [0 for x in range(26)]
        g = [False for x in range(26)]
        ans = 1
        group = 0
        for i in s:
            g[ord(i[0])-97] = True
            g[ord(i[-1])-97] = True
            if i[0] != i[-1]:
                p1 = ord(i[0]) - 97
                p2 = ord(i[-1]) - 97
                if a[p1] != -1 or b[p2] != -1:
                    bl = False
                a[p1], b[p2] = p2, p1
                group += 1
            else:
                f[ord(i[0])-97] += 1
        group = len([0 for x in g if x == True]) - group
        if not bl:
            print "Case #%d: 0"%I
        else:
            for x in f:
                if x > 0:
                    ans = (ans * x) % 1000000007
            ans = (ans * group) % 1000000007
            print "Case #%d: %d"%(I, ans)

            


        


