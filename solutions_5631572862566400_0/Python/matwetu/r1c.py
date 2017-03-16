from collections import Counter



def deepest(node,   c, rs):
    d = [0]
    for child in rs[node]:
        if child not in c:
            d.append(deepest(child, c, rs))
    return max(d) + 1
    
def circles(s):
    ret = []
    checked = set()
    for node in s:
        if node in checked: continue
        mark = set()
        cur = node
        while 1:
            if cur in mark:
                break
            mark.add(cur)
            cur = s[cur]
        if cur == node:
            ret.append(mark)
            checked  |= mark
    return ret
def solve(s):
    rs = {i:[] for i in range(len(s))}
    for i,j in enumerate(s):
        rs[j].append(i)
    listc = circles(s)
    #print(listc)
    #print(rs)
    ret = 0
    for c in listc:
        if len(c) > 2: continue
        lista = []
        for node in c:
            a = deepest(node, c, rs)
            #print(node, a)
            lista.append(a-1)
        ret += sum(sorted(lista)[-2:]) + len(c)
    m = max(map(len, listc))
    return max(ret,m)
    
M=int(input())
for caseid in range(1, M+1):
    N = int(input())
    S = list(map(lambda x:int(x) - 1,input().strip().split()))
    print("Case #%d: %s" % (caseid, solve(S)))