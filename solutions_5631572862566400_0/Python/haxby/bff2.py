def bff(lst):
    j=0
    b = []
    for pos, nex in enumerate(lst):
        i=[pos+1]
        f = False
        g = False
        c=0
        while c < len(lst):
            c+=1
            i.append(nex)
            nex = lst[nex-1]
            if nex ==i[0]:
                f = True
                break
            if nex == i[-2]:
                f = True
                g = True
                break
        if f:
            b.append((i,g))

    best = []
    g = [i[0] for i in b if i[1]]
    h = [i[0] for i in b if not i[1]]
    for i in range(len(g)):
        s = g[i]
        for j in g[i+1:]:
            if all([1 if x not in s else 0 for x in j]):
                s.extend(j)
        x = [q+1 for q in range(len(lst)) if (lst[q]==s[0] or lst[q]==s[-1]) and q+1 not in s]
        if x:
            for z in x:
                if z not in s:
                    s.append(z)
        if len(s) > len(best):
            best = s


    for i in h:
        if len(i) > len(best):
            best = i
    return len(best)


    
n = int(raw_input())
for i in range(n):
    num = eval(raw_input())
    lst = map(int, raw_input().split())
    circle = bff(lst)
    print "Case #{0}: {1}".format(i+1, circle)
    
