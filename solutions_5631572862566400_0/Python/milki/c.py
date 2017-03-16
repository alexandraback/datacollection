import networkx as nx
from collections import defaultdict

result = None
supernode = None

def p(*args):
    return
    print(' '.join(map(str, args)))

def main():
    global supernode, result
    T = int(raw_input())
    for t in xrange(T):
        N = int(raw_input())
        g = nx.DiGraph()
        supernode = defaultdict(int)
        bff = [0]
        input = map(int, raw_input().split())
        for idx, n in enumerate(input):
            g.add_path([idx+1, n])
            bff.append(n)
        ret = 0
        for i in g.nodes():
            for j in g.nodes():
                if i == j:
                    continue
                for path in nx.all_simple_paths(g, i, j):
                    p(path)
                    if not path or len(path) == 1:
                        continue
                    if bff[path[-1]] != path[0] and bff[path[-1]] != path[-2]:
                        continue
                    if path[-2] == bff[path[-1]]:
                        supernode[(path[-2], path[-1])] = max(supernode[(path[-2], path[-1])], len(path) - 2)
                    if len(path) > ret:
                        ret = len(path)
        for s1, s2 in supernode.keys():
            p(s1, s2)
            tt = supernode[(s2, s1)] + supernode[(s1, s2)] + 2
            assert len(supernode) % 2 == 0
            if tt + len(supernode) / 2 - 1 > ret:
                ret = tt + len(supernode) / 2 - 1 
        output(t, ret, input)


def output(casenum, ret, input):
    print 'Case #%d: %s' % (casenum + 1, ret)
    # print ' '.join(map(str,input))
    # print ''


main()
