

def depth(this, other, bffg_rev):
    if this not in bffg_rev:
        return 1
    bffs = [bff for bff in bffg_rev[this] if bff is not other]
    if len(bffs) == 0:
        return 1
    return max(map(lambda that: depth(that, other, bffg_rev)+1,bffs))

for case in range(int(raw_input())):
    n    = int(raw_input())
    bffg = {}
    bffg_rev = {}
    bffs = map(lambda c: int(c) - 1, raw_input().split())
    for c in range(n):
        bff = bffs[c]
        bffg[c] = bff
        if bff not in bffg_rev:
            bffg_rev[bff] = []
        bffg_rev[bff].append(c)

#    print bffg
#    print bffg_rev

    todo = set(range(n))
    components_pre = []
   
    seen = set()
    
    for node in bffg:
       if node not in seen:
           component = []
           nodes = set([node])
           while nodes:
               node2 = nodes.pop()
               seen.add(node2)
               if node2 in bffg_rev:
                   nodes |= set(bffg_rev[node2])
               nodes |= set([bffg[node2]])
               nodes -= seen
               component.append(node2)
           components_pre.append(component)
 
#    while todo:
#        visited = set()
#        x = todo.pop()
#        print x
#        while x not in visited:
#            visited.add(x)
#            x = bffg[x]
#        components.append((x,visited))
#        print (x,visited)
#        todo -= visited

    components = []
    for component in components_pre:
        visited = set()
        x = component[0]
        while x not in visited:
            visited.add(x)
            x = bffg[x]
        components.append((x,component))

    sizes = []
    max_size = 0

    for (loopstart, ixes) in components:
        looplen = 0
        visited = set()
        x = loopstart
        while x not in visited:
            visited.add(x)
            x = bffg[x]
            looplen += 1
        if looplen > 2:
            max_size = max(max_size, looplen)
            continue
        y = bffg[x]
        sizes.append(depth(x,y, bffg_rev) + depth(y,x, bffg_rev))
    
    comb = sum(sizes)
    max_size = max(max_size,comb)

    print "Case #%d: %s" % (case+1, max_size)

