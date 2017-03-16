import sys
sys.setrecursionlimit(150000000)

T = int(input())

def find(x, v):
    global edge, parent
    for i in edge[x]:
        if i not in v:
            v.add(i)
            if i not in parent or find(parent[i], v):
                parent[i] = x
                return True
    return False



for case in range(1, T + 1):
    edge = {}
    parent = {}
    dx = set()
    dy = set()
    n = int(input())
    ans = 0
    for xx in range(n):
        line = input()
        t = line.split()
        x = t[0]
        y = t[1]
        if x not in dx:
            ans+=1
            dx.add(x)
        if y not in dy:
            ans+=1
            dy.add(y)
        edge.setdefault(x, [])
        edge[x].append(y)
    for k in edge:
        v = set()
        if find(k, v):
            ans-=1
    print("Case #{0}: {1}".format(case, n - ans))
