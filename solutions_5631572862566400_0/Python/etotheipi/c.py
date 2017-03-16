IN = open('input.txt', 'r')
OUT = open('output.txt', 'w')
INF = 10000

NUM_TESTS = int(IN.readline())

def findDepth(id):
    if depth[id] != INF: return
    #OUT.write('{}\n'.format(', '.join(map(str, depth))))
    #OUT.write('{}\n'.format(', '.join(map(str, friendOf))))
    #OUT.write('find depth {}\n'.format(id))
    findDepth(friendOf[id])
    depth[id] = depth[friendOf[id]] + 1
    root[id] = root[friendOf[id]]

for test in xrange(NUM_TESTS):
    N = int(IN.readline())
    friendOf = map(int,IN.readline().split())
    friendOf.insert(0, 0)
    
    # first find the cycles
    found = []
    cycle = []
    for id in xrange(1, N+1): # todo: O(N^2). Needs to be improved
        x = id
        for i in xrange(N): 
            x = friendOf[x]
        if x in found:
            continue
        
        c = [x, friendOf[x]]
        while c[0] != friendOf[c[-1]]:
            c.append(friendOf[c[-1]])
        cycle.append(c)
        found.extend(c)
        
    #print cycle
    
    # then get distance to cycles from each node
    depth = [INF] * (N+1)
    root = [-1] * (N+1)
    for c in cycle:
        for id in c:
            depth[id] = 0
            root[id] = id
    for id in xrange(1, N+1):
        findDepth(id)
    
    # finally compute the answer
    answer = 0
    two = []
    for c in cycle:
        answer = max(answer, len(c))
        if len(c) == 2:
            bestA = 0
            bestB = 0
            for id in xrange(1, N+1):
                if root[id] == c[0] and depth[id] > bestA:
                    bestA = depth[id]
                if root[id] == c[1] and depth[id] > bestB:
                    bestB = depth[id]
            two.append(2 + bestA + bestB)
    answer = max(answer, sum(two))
        
    OUT.write('Case #{}: {}\n'.format(test+1, answer))
    print test+1, answer

IN.close()
OUT.close()
