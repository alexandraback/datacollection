with open('garbled_email_dictionary.txt', 'r') as file:
    words = file.read().split()

def maketree(words):
    def addprefix(tree, w):
        for i in range(len(w)):
            c = w[i]
            if c not in tree:
                tree[c] = {}
            tree = tree[c]
        tree[''] = w

    tree = {}
    for w in words:
        addprefix(tree, w)
    return tree

from collections import namedtuple
State = namedtuple('State', ['left', 'tree', 'change', 'cost'])

prefix = maketree(words)

def solve(message):
    frontier = [State(message, prefix, 0, 0)]
    visited = set()

    # count = 0
    while frontier:
        # count += 1
        top = frontier[0]
        del frontier[0]

        if (top.left, id(top.tree), top.change, top.cost) in visited:
            # print (top.left, id(top.tree), top.change, top.cost)
            continue
        visited.add((top.left, id(top.tree), top.change, top.cost))

        # print (top.left, top.change, top.cost)

        if not top.left:
            if '' in top.tree:
                # print count
                return top.cost
            else:
                continue

        if top.change > 0:
            # the letter must be identical
            c = top.left[0]
            if c in top.tree:
                frontier.append(State(top.left[1:], top.tree[c], top.change - 1, top.cost))
            if '' in top.tree and c in prefix:
                frontier.append(State(top.left[1:], prefix[c], top.change - 1, top.cost))
        else:
            # allow changes
            for c in top.tree:
                if c != '':
                    if c == top.left[0]:
                        frontier.append(State(top.left[1:], top.tree[c], 0, top.cost))
                    else:
                        frontier.append(State(top.left[1:], top.tree[c], 4, top.cost + 1))
                else:
                    # new word
                    for d in prefix:
                        if d == top.left[0]:
                            frontier.append(State(top.left[1:], prefix[d], 0, top.cost))
                        else:
                            frontier.append(State(top.left[1:], prefix[d], 4, top.cost + 1))
        frontier.sort(key = lambda item: item.cost)

with open('C-small-attempt0.in', 'r') as file:
    T = int(file.readline())
    for case in range(1, T+1):
        message = file.readline().strip()
        print 'Case #{}: {}'.format(case, solve(message))
