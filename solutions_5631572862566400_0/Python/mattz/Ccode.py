import sys

# INPUT DATA AND NUMBER OF TEST CASES
infile = open(sys.argv[1],'r')
T = infile.readline()
T = T.rstrip()

# ITERATE OVER EACH CASE
for index in range(1,int(T)+1):
    N = int(infile.readline().rstrip())
    BFF = infile.readline().rstrip().split(' ')

    # FIND RECIPROCATE BFFs AND NON BFFs
    sinks = []
    nodes = []
    for i in range(N):
        BFF[i] = int(BFF[i]) - 1
    
    for i in range(N):
        if BFF[BFF[i]] == i:
            sinks.append(i)
        if i not in BFF:
            nodes.append(i)


    # FIND EVENTUAL PATH TRACED FROM NON BFFs
    node2sink = []
    loop = []
    node2loop = []
    kids = range(N)
    for node in nodes:
        path = [node]
        crawler = node
        kids.remove(node)
        while BFF[crawler] not in path:
            path.append(BFF[crawler])
            crawler = BFF[crawler]
            if crawler in kids:
                kids.remove(crawler)

        if crawler in sinks:
            node2sink.append([node, crawler, len(path)])
        else:
            intersection = path.index(BFF[crawler])
            loop.append([BFF[crawler], crawler, len(path) - intersection])
            if intersection > 0:
                node2loop.append([node, path[intersection - 1], intersection])


    # FIND OTHER LOOPS
    while len(kids) > 0:
        path = [kids[0]]
        crawler = kids[0]
        kids.remove(kids[0])
        while BFF[crawler] not in path:
            path.append(BFF[crawler])
            crawler = BFF[crawler]
            if crawler in kids:
                kids.remove(crawler)

        intersection = path.index(BFF[crawler])
        loop.append([BFF[crawler], crawler, len(path) - intersection])

    longest_loop = 0;
    num_islands = 0
    for l in loop:
        if l[2] > longest_loop:
            longest_loop = l[2]
        if l[2] == 2:
            num_islands += 1

    longest_n2s = {}
    for path in node2sink:
        sink = path[1]
        length = path[2]
        if sink not in longest_n2s.keys():
            longest_n2s[sink] = length
        else:
            if length > longest_n2s[sink]:
                longest_n2s[sink] = length

    longest_n2s2n = 0
    longest_bridges = []
    for sink in longest_n2s.keys():
        if (BFF[sink] in longest_n2s.keys()):
            combined_len = longest_n2s[sink] + longest_n2s[BFF[sink]] - 2
            if combined_len > longest_n2s2n:
                longest_n2s2n = combined_len
            if BFF[sink] > sink:
                longest_bridges.append(max(longest_n2s[sink], longest_n2s[BFF[sink]]))
        else:
            longest_bridges.append(longest_n2s[sink])

    circles = []
    circles.append(longest_loop)
    circles.append(longest_n2s2n + sum(longest_bridges) + 2 * num_islands)    # OUTPUT IN THE FORM
    print 'Case #' + str(index) + ': ' + str(max(circles))
