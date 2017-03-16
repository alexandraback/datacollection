#!py -3

from sys import stderr, stdin, stdout

def main():
    """
    The first line of the input gives the number of test cases, T. T test cases follow.
        
    Each test case consists of two lines.
        
        The first line of a test case contains a single integer N, the total number of kids in the class.

        The second line of a test case contains N integers F1, F2, ..., FN, where Fi is the student ID number of the BFF of the kid with student ID i. 
 
 
    """
    
    for i in range(int(input())):
        
        ## INPUT ##
        n = int(input())
        # f = list(map(int, input().strip().split()))
        f = [int(x) - 1 for x in input().strip().split()]
            # stupid 1-indexing.
        assert len(f) == n
        
        ## OUTPUT ##
        
        ans = solve(f)
        
        ## PRINT ##

        print("Case #%d:" % (i+1), ans)


#return: biggest circle.
def solve(f):
    """
    Limits

        1 = T = 100.
        1 = Fi = N, for all i.
        Fi ? i, for all i. (No kid is their own BFF.)

    Small dataset
        3 = N = 10.
    Large dataset
        3 = N = 1000.

    """
    # Need to be able to know:
        # For each kid, who their BFF is. (This is `f`.)
        # For each kid, who BFFs them.
    
    # graph[k] := list[<kids whose bf is k>]
    graph = bucketize(f)
    
    # Two ways of adding to the circle:
    # 1. Cycle. This takes up the whole circle.
    # 2. Chain: Two kids who are mutual BFf, and then a chain off of each of them (possibly nonempty).
    #     a -> b -> c <-> d <- e <- f
    
    # Each child is either a straggler, or in a cycle.
    
    
    # Well, the length is what matters.
    #   so these return ints, despite naming.s
    cycles, stragglers = divvy(graph)
    
    kchain = biggest_chain(cycles, stragglers, graph)
        #kchain first because kcycle is destructive.
    kcycle = biggest_cycle(cycles)
    
    print(file=stderr)
    print("Friends:", *f, file=stderr)
    print("Cycles, chains:", kcycle, kchain, file=stderr)
    
    return max(kcycle, kchain)


def divvy(g):
    """
    Divides graph up into cycles and stragglers.
    """
    
    graph = dict(enumerate(map(set, g)))
    
    ## Isolate stragglers. ##
    
    # Find no-incoming-edges.
    lonely = set(k for k, b in graph.items() if not b)
    all_lonely = lonely
    while lonely and graph:
        newgraph = []
        newlonely = []
        for k, b in graph.items():
            b -= lonely
            if b:
                newgraph.append((k, b))
            else:
                newlonely.append(k)
        graph, lonely = dict(newgraph), set(newlonely)
        all_lonely |= lonely
    
    assert all(len(v) == 1 for v in graph.values())
    g1 = {k: v.pop() for k, v in graph.items()}
    
    return g1, all_lonely



def biggest_cycle(cycles):
    def trace(v):
        c = 0 #i off-by-one'd here ._.
        while v is not None:
            v = cycles.pop(v, None)
            c += 1
        return c
    
    best = 0
    while cycles:
        best = max(best, trace(cycles.popitem()[1]))
    
    return best


#
def biggest_chain(cycles, stragglers, graph):
    # Find two-cycles.
    loops = set()
    # Pick pairs where k0 < k1.
    for k, v in cycles.items():
        if cycles[v] == k:
            if k > v:
                k,v = v,k
            loops.add((k,v))
    
    # longest chain for this kid
    def longest_of(k, k0):
        q = (k,)
        depth = 0 # this kid
        while q:
            q = [kj for ki in q
                        for kj in graph[ki]
                            if kj != k0]
            # there shouldn't be any other cycles.
            depth += 1
        
        return depth
    
    return sum(
        (longest_of(k0, k1) + longest_of(k1, k0)
            for k0, k1 in loops),
    )
    
    


def bucketize(f):
    buckets = [[] for _ in range(len(f))]
    
    for i, k in enumerate(f):
        buckets[k].append(i)
    
    return buckets

if __name__ == '__main__':
    main()

