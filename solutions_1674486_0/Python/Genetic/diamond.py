def main(filein):
    f = open(filein, "r")
    outname = filein.split(".")[0] + "OUT.txt"
    g = open(outname, "w")

    count = -1
    isN = True
    ncount = 0
    info = []
    for line in f:
        count += 1
        if count == 0:
            continue
        if isN:
            count -= 1
            isN = False
            ncount = int(line)
            info.append(ncount)
            continue
        if ncount > 0:
            info.append([int(x) for x in line.split(" ")])
            ncount -= 1
            if ncount > 0:
                count -= 1
                continue
            if ncount == 0:
                isN = True
        newline = "Case #" + str(count) + ": " + code(info) + "\n"
        info = []
        g.write(newline)
    f.close()
    g.close()
    
def code(info):
    N = info[0]
    info = info[1:]
    d = {}
    for (i,e) in enumerate(info):
        d[i+1] = e[1:]
        
    # turn it into an undirected adjacency list
    '''for (i,e) in enumerate(info):
        i = i + 1
        e = e[1:]
        for val in e:
            d[val] = (d[val] + [i])'''
    
    overall = []
    
    for (k,vals) in d.iteritems():
        for v in vals:
            thing = (k,v)
            overall.append((k,v))
    
    results = []
    left = range(1,N+1)
    while left != []:
        results += allPathsFromN(left[0], overall)
        for (n,_) in results:
            print n
            if n in left:
                left.remove(n)
    

    for (_,lst) in results:
        lst.sort()
        for i in range(len(lst) - 1):
            if lst[i] == lst[i+1]:
                return "Yes"
    return "No"

def allPathsFromN(init, overall):
    first = []
    others = []
    for (x,y) in overall:
        if x == init:
            ys = allPathsFromN(y, overall)
            for (y,z) in ys:
                first.append(y)
                #first.extend(z)
            others.extend(ys)
    return [(init,first)] + others