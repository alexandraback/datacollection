T = int(raw_input())
for i in range(T):
    print "Case #"+str(i+1)+":",

    C,J = raw_input().split(' ')
    l = len(C)
    q = [(C,J)]
    mind,minc,minj = 1000,1000,1000
    while q!=[]:
        c,j = q.pop()
        if '?' in c:
            index = c.index('?')
            for k in range(10):
                q.append((c[:index]+str(k)+c[index+1:],j))
            continue
        if '?' in j:
            index = j.index('?')
            for k in range(10):
                q.append((c,j[:index]+str(k)+j[index+1:]))
            continue
        c = int(c)
        j = int(j)
        d = abs(int(c)-int(j))
        if d < mind:
            mind = d
            minc = c
            minj = j
        elif d == mind and c < minc:
            minc = c
            minj = j
        elif d == mind and c == minc and j < minj:
            minj = j
    print str(minc).zfill(l),str(minj).zfill(l)


