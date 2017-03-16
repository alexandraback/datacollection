
t = int(input())
for i in range(1, t + 1):
    n = int(input())
    l = [int(s)-1 for s in input().split(" ")]
    optional = set([j for j in range(n)])
    mC = 0
    for j in range(n):
        s = set()
        s.add(j)
        t = l[j]
        while not t in s:
            s.add(t)
            t = l[t]
        if j==t:
            if mC < len(s):
                mC = len(s)
            optional = optional.difference(s)
    couples = [(j,l[j]) for j in range(n) if j==l[l[j]]]
    optional = optional.difference([x[0] for x in couples])
    #print(couples)
    lines = [0 for j in range(len(couples))]
    m = 0
    for j in optional:
        s = set()
        s.add(j)
        last = j
        t = l[j]
        while not t in s:
            s.add(t)
            last = t
            t = l[t]
        if l[t]==last:
            tmp = couples.index((t,l[t]))
            if lines[tmp] < len(s)-2:
                lines[tmp] = len(s)-2
    m = sum(lines)+len(couples)
    #print(mC, m)
    #print(lines)
    #print(couples)
    print("Case #{}: {}".format(i, max(mC,m)))
