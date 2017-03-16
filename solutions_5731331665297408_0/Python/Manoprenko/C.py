def dfs(u):
    global used, al, res, cost
    used[u] = True
    res += str(cost[u])
    a = [[i, cost[i]] for i in al[u]]
    a.sort(key=lambda x: x[1])
    for i in a:
        if not used[i[0]]:
            dfs(i[0])

fin = open("C-small-attempt2.in", "r")
fout = open("C Small Answer.txt", "w")

t = int(fin.readline())
for cycle in range(t):
    n, m = [int(i) for i in fin.readline().split()]
    cost = []
    for i in range(n):
        cost.append(int(fin.readline()))
    al = [[] for i in range(n)]
    used = [False] * n
    for i in range(m):
        a, b = [int(i) - 1 for i in fin.readline().split()]
        al[a].append(b)
        al[b].append(a)
    res = ""
    mini = 0
    for i in range(n):
        if cost[i] < cost[mini]:
            mini = i
    dfs(mini)
    if len(res) != n * 5:
        print("WTF?!")
        exit()
    print("Case #", cycle + 1, ": ", res, sep="", file=fout)

fin.close()
fout.close()