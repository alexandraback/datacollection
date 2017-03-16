def solve(testnum):
    n,m = [int(x) for x in input().split()]
    nodes = [int(input()) for i in range(n)]
    edges = [tuple([int(x)-1 for x in input().split()]) for i in range(m)]
    edgel = [[] for i in range(n)]
    for e in edges:
        edgel[e[0]].append(e[1])
        edgel[e[1]].append(e[0])
    edgeldic = dict([(nodes[i],[]) for i in range(n)])
    for e in edges:
        edgeldic[nodes[e[0]]].append(nodes[e[1]])
        edgeldic[nodes[e[1]]].append(nodes[e[0]])
    for node in nodes:
        edgeldic[node].sort()
    nodepreindex = dict([(nodes[i],i) for i in range(n)])
    sortednodes = sorted(nodes)
    #start = nodepreindex[min(nodes)]
    start = min(nodes)
    def recur(s,loc,used,border,path):
        #print("Recur:",s,loc,used,border,path)
        for node in sorted(border):
            newused = used.union(set([node]))
            newborder = border.copy()
            newpath = [(seg[0],seg[1].copy()) for seg in path]
            while node not in newpath[-1][1]:
                for node2 in newpath[-1][1]:
                    newborder[node2] -= 1
                    if newborder[node2] == 0:
                        del newborder[node2]
                newpath.pop()
            del newborder[node]
            for seg in newpath:
                seg[1].difference_update(set([node]))
            newpath.append((node,set(edgeldic[node]).difference(newused)))
            for node2 in newpath[-1][1]:
                if node2 not in newborder: newborder[node2] = 0
                newborder[node2] += 1
            #print(node,newused,newborder,newpath)
            res = recur(s+str(node),node,newused,newborder,newpath)
            if res: return res
        if len(used) == n:
            return s
        return False
    s = recur(str(start),start,set([start]),dict([(n,1) for n in edgeldic[start]]),
              [(start,set(edgeldic[start]))])
    print("Case #%d: %s"%(testnum,s))

for i in range(int(input())): solve(i+1)
