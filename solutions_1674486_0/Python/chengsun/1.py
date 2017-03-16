
GSIZ=1001



T = int(input())
for TT in range(T):
    adjlist = [None]*(GSIZ)
    for i in range(len(adjlist)):
        adjlist[i] = []

    def nways(node):
        if nway[node] is None:
            su = 0
            for parent in adjlist[node]:
                su += nways(parent)
            nway[node] = su
        return nway[node]

    N = int(input())
    for s in range(1,N+1):
        inp = [int(x) for x in input().split(' ')]
        inp.pop(0)
        for t in inp:
            adjlist[t].append(s)
    found = False
    for source in range(1, N+1):
        nway = [None]*GSIZ
        nway[source] = 1
        for sink in range(1, N+1):
            if nways(sink) > 1:
                found = True
                break
        if found:
            break
    print("Case #" + str(TT+1) + ": " + ("Yes" if found else "No"))



