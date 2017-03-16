from __future__ import division

alphabet = "abcdefghijklmnopqrstuvwxyz"

def debug(k):
    return 
    print k

def dfs(v, es, visited):
    visited.add(v)
    for e in es:
        if e[0] == v:
            if e[1] in visited:
                return True
            else:
                if dfs(e[1], es, visited):
                    return True
    return False

def findCycle(vs, es):
    visited = set()
    cnt = 0
    for v in vs:
        flag = 0
        for e in es:
            if e[1] == v:
                flag = 1
        if flag:
            continue
        if not v in visited:
            if dfs(v, es, visited):
                return -1
            cnt += 1

    for v in vs:
        if not v in visited:
            return -1
    return cnt

def fakeFrac(n, BS):
    ans = 1
    for i in range(n):
        ans *= (i + 1)
        ans %= BS
    return ans

def solve(n, ss):

    occ_list = []
    for s in ss:
        occ = set()
        bc = '$'
        for c in s + "#":
            if c in occ:
                return 0
            if c != bc and bc != "$":
                occ.add(bc)
            bc = c
        occ_list.append(occ)
    debug("acbca")

    for i in range(n):
        s = ss[i]
        inners = s.lstrip(s[0])
        inners = inners.rstrip(s[-1])
        for c in inners:
            for j in range(n):
                if i != j and c in occ_list[j]:
                    return 0

    debug("acb cc")
    islands = []
    edges = []
    for s in ss:
        if s[0] != s[-1]:
            edges.append((s[0], s[-1]))
        else:
            islands.append(s[0])

    debug(edges)
    out_reg = set()
    in_reg = set()
    for e in edges:
        if e[0] in in_reg:
            debug("ac ab")
            return 0
        else:
            in_reg.add(e[0])
        if e[1] in out_reg:
            debug("ac bc")
            return 0
        else:
            out_reg.add(e[1])

    nodes = set([e[0] for e in edges]) | set([e[1] for e in edges])
    debug(nodes)
    k = findCycle(nodes, edges)
    if k == -1:
        debug("ac ca")
        return 0
    
    debug((k, islands))
    reg = in_reg | out_reg
    for c in islands:
        if not c in reg:
            k += 1
            reg.add(c)
    ans = 1
    BS = 1000000007
    ans *= fakeFrac(k, BS)
    ans %= BS
    for c in alphabet:
        k = sum([1 for i in islands if i == c])
        ans *= fakeFrac(k, BS)
        ans %= BS

    return ans

def perm(l):  
    if(len(l)<=1):  
        return [l]  
    r=[]  
    for i in range(len(l)):  
        s=l[:i]+l[i+1:]  
        p=perm(s)  
        for x in p:  
            r.append(l[i:i+1]+x)  
    return r  

def naivesolve(n, ss):
    ans = 0
    for each in perm(range(n)):
        reg = set()
        qs = ""
        for i in each:
            qs += ss[i]
        #print qs
        bc = "$"
        for c in qs + "#":
            if c in reg:
                break
            else:
                if c != bc:
                    reg.add(bc)
                bc = c
        else:
            ans += 1
    return ans

def main():
    tc = input()
    for tid in range(1, tc + 1):
        n = input()
        sall = raw_input()
        ss = sall.split(' ')
        #ans = (solve(n, ss), naivesolve(n, ss))
        #print "Case #%d: %d %d" % (tid, ans[0], ans[1])
        ans = solve(n, ss)
        print "Case #%d: %d" % (tid, ans)

if __name__ == "__main__":
    main()
