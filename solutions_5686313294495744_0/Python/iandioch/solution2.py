import sys

class StartNode:
    def __init__(self, _id):
        self._id = _id
        self.exits = []

    def add_exit(self, n):
        self.exits.append(n)
    
    def __str__(self):
        return str(self._id) + ' - ' + str(len(self.exits))

n = int(sys.stdin.readline())

for test in xrange(1, n+1):
    m = int(sys.stdin.readline())
    lines = []
    for i in xrange(m):
        lines.append(sys.stdin.readline().split())

    nodes = {}

    nodes[0] = StartNode(0)

    for l in lines:
        s = 'end_' + l[1]
        if s in nodes:
            continue
        nodes[s] = StartNode(s)
        nodes[s].add_exit(nodes[0])

    for l in lines:
        s = 'start_' + l[0]
        e = 'end_' + l[1]
        if s in nodes:
            nodes[s].add_exit(nodes[e])
        else:
            nodes[s] = StartNode(s)
            nodes[s].add_exit(nodes[e])
            nodes[0].add_exit(nodes[s])


    ans = 0
    for i in xrange(len(lines)-1, -1, -1):
        l = lines[i]
        s = 'start_' + l[0]
        e = 'end_' + l[1]
        g = lines[:]
        del g[i]
        reached = set()
        for line in g:
            t = nodes['start_' + line[0]]
            reached.add(t._id)
            for r in t.exits:
                reached.add(r._id)
        if len(reached) == len(nodes) -1:
            ans += 1
            del lines[i]

    print 'Case #{}: {}'.format(test, ans)
