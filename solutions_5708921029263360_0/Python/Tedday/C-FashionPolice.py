level = __file__.split("\\")[-1][0]
file_is_small = True
attempt = 1
name = level+"-small-attempt"+str(attempt) if file_is_small else level+"-large"
input_file = file(name+".in","r")
output_file = file(name+"-output.txt","w")
edges = [[[1,1]],[[1,1],[1,2]],[[1,1],[1,2],[1,3]],

    
    ]
def test_case():
    [J,P,S,K] = [int(i) for i in input_file.readline().split()]
    edges = []
    """
    for p in xrange(0,P):
        for s in xrange(0,S):
            edges.append([p,s])
    """
    e1 = range(1,P+1) * S
    e2 = range(1,S+1)
    for i in xrange(S):
        edges += (e2[i:] + e2[:i])
    edges = [list(i) for i in zip(e1,edges)]
    """
    pants = [0] * P
    shirt = [0] * S
    new_edges = []
    for l in xrange(len(edges)):
        min_p = min(pants)
        min_s = min(shirt)
        for e in edges:
            if(e[0] == (l%P) and pants[e[0]] == min_p and shirt[e[1]] == min_s):
                break
        new_edges.append([x+1 for x in e])
        edges.remove(e)
        pants[e[0]]+=1
        shirt[e[1]]+=1
    """
    pants = [0] * P
    shirt = [0] * S
    #edges = new_edges
    jacket = 1
    sets = []
    for i in xrange(J):
        for e in edges:
            if(min(pants) == K or min(shirt) == K):
                pants = [0] * P
                shirt = [0] * S
                jacket += 1
                if(jacket > J):
                    break
            sets.append("{0} {1} {2}".format(jacket,e[0],e[1]))
            pants[e[0]-1] +=1
            shirt[e[1]-1] +=1
        if(jacket > J):
            break
    
    return str(len(sets)) + "\n" + "\n".join(sets)
    
T = int(input_file.readline())
for test in xrange(T):
    out = "Case #{0}: {1}".format(test+1,test_case())
    #print out
    output_file.write(out + "\n")
input_file.close()
output_file.close()
