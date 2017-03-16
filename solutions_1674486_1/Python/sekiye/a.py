class Node:
    def __init__(self, children):
        self.visited = False
        self.parent = None
        self.children = children

def find_diamond(tree, i):
    tree[i].visited = True
    for child in tree[i].children:
        if tree[child].visited:
            return True
        else:
            if find_diamond(tree, child):
                return True
    return False

def solve():
    N = int(raw_input())
    tree = []
    for i in xrange(N):
        children = map(lambda x: int(x) - 1, raw_input().split())[1:]
        n = Node(children)
        tree.append(n)
    for i in xrange(N):
        for child in n.children:
            tree[child].parent = i
    for i in xrange(N):
        for j in xrange(N):
            tree[j].visited = False
        if find_diamond(tree, i):
            return "Yes"
    return "No"

T = int(raw_input())
for i in range(T):
    print "Case #%d:" % (i + 1), solve()
