from collections import defaultdict
import sys


def search(ch, node, path, ends, paths):
    for i in range(len(path) - 1):
        p = path[i:]
        se = (p[0], p[-1])
        if se in ends:
            if p != paths[se]:
                return True
        else:
            ends.add(se)
            paths[se] = p
    for child in ch[node]:
        if search(ch, child, path + (child,), ends, paths):
            return True
    return False


inp = sys.stdin

T = int(inp.readline())
for case_number in range(1, T + 1):
    N = int(inp.readline())
    children = defaultdict(list)
    roots = []
    for i in range(1, N + 1):
        ancestors = map(int, inp.readline().split())
        M = ancestors.pop(0)
        assert M == len(ancestors)
        if not M:
            roots.append(i)
        for a in ancestors:
            children[a].append(i)
    ends = set()
    paths = {}
    for root in roots:
        if search(children, root, (root,), ends, paths):
            break
    else:
        print 'Case #%d: No' % case_number
        continue
    print 'Case #%d: Yes' % case_number


