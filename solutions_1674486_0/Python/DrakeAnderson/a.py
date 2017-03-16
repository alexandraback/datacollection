from sys import stdin
inheritances = list()

t = int(stdin.readline()) + 1
for i in range(1, t):
    n = int(stdin.readline())
    inheritances = list()
    for j in range(0,n):
        inheritances_row = list()
        m_in = stdin.readline().strip().split(" ")
        num = int(m_in[0]) + 1
        for k in range(1,num):
            inheritances_row.append(int(m_in[k])-1)
        inheritances.append(inheritances_row)
    diamond = False
    for j in range(0, n):
        inheritance_dict = dict()
        q = list()
        q.append(j)
        while(q and not diamond):
            node = q.pop(0)
            node_inheritance = inheritances[node]
            for n2 in node_inheritance:
                if n2 in inheritance_dict:
                    inheritance_dict[n2] += 1
                    diamond = True
                else:
                    inheritance_dict[n2] = 1
                    q.append(n2)
        if diamond:
            break
    print "Case #%d: %s" % (i, ("Yes" if diamond else "No"))
