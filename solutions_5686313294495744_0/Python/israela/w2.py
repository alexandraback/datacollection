import sys
import networkx as nx
from networkx.algorithms import bipartite


import collections
import itertools

from networkx.algorithms.bipartite import sets as bipartite_sets

__all__ = ['maximum_matching', 'hopcroft_karp_matching', 'eppstein_matching',
           'to_vertex_cover']

INFINITY = float('inf')


def hopcroft_karp_matching(G):
    def breadth_first_search():
        for v in left:
            if leftmatches[v] is None:
                distances[v] = 0
                queue.append(v)
            else:
                distances[v] = INFINITY
        distances[None] = INFINITY
        while queue:
            v = queue.popleft()
            if distances[v] < distances[None]:
                for u in G[v]:
                    if distances[rightmatches[u]] is INFINITY:
                        distances[rightmatches[u]] = distances[v] + 1
                        queue.append(rightmatches[u])
        return distances[None] is not INFINITY

    def depth_first_search(v):
        if v is not None:
            for u in G[v]:
                if distances[rightmatches[u]] == distances[v] + 1:
                    if depth_first_search(rightmatches[u]):
                        rightmatches[u] = v
                        leftmatches[v] = u
                        return True
            distances[v] = INFINITY
            return False
        return True

    # Initialize the "global" variables that maintain state during the search.
    left, right = bipartite_sets(G)
    leftmatches = {v: None for v in left}
    rightmatches = {v: None for v in right}
    distances = {}
    queue = collections.deque()

    # Implementation note: this counter is incremented as pairs are matched but
    # it is currently not used elsewhere in the computation.
    num_matched_pairs = 0
    while breadth_first_search():
        for v in left:
            if leftmatches[v] is None:
                if depth_first_search(v):
                    num_matched_pairs += 1

    # Strip the entries matched to `None`.
    leftmatches = {k: v for k, v in leftmatches.items() if v is not None}
    rightmatches = {k: v for k, v in rightmatches.items() if v is not None}

    # At this point, the left matches and the right matches are inverses of one
    # another. In other words,
    #
    #     leftmatches == {v, k for k, v in rightmatches.items()}
    #
    # Finally, we combine both the left matches and right matches.
    return dict(itertools.chain(leftmatches.items(), rightmatches.items()))



#maximum_matching = hopcroft_karp_matching


def solve(n, first_words, second_words):
    #g = nx.Graph()
    g = nx.DiGraph()
    g.add_nodes_from(list(set(first_words)), bipartite=0)
    g.add_nodes_from(list(set(second_words)), bipartite=1)

    for i in xrange(n):
        g.add_edges_from([(first_words[i], second_words[i])])

    #mm = nx.matching.maximal_matching(g)
    #nx.maximal_matching()
    mm = hopcroft_karp_matching(g)
#    vertex_cover = nx.bipartite.to_vertex_cover(g, mm)
#    independent_set = set(g) - vertex_cover

    return n - (len(mm) / 2)

def solve2(n, first_words, second_words):
    dic = {}
    for w in first_words:
        dic[w] = set()
    for i in xrange(n):
        dic[first_words[i]].add(second_words[i])

    res = 9999999
    w = dic.keys()[0]
    for w2 in dic[w]:
        # try to add edge w,w2
        if first_words[i] == w:
            p = 0

    return 5


def solve1(n, first_words, second_words):
    num_of_org = 0
    org_first = set()
    org_second = set()
    non_org_indx = set()
    for i in xrange(n):
        if first_words.count(first_words[i]) == 1 or second_words.count(second_words[i]) == 1:
            num_of_org += 1
            org_first.add(first_words[i])
            org_second.add(second_words[i])
        else:
            non_org_indx.add(i)

    non_explained = set()
    for i in non_org_indx:
        if first_words[i] not in org_first or second_words[i] not in org_second:
            non_explained.add(i)

    while len(non_explained) != 0:
        b = True
        for i in non_explained:
            if first_words[i] not in org_first and second_words[i] not in org_second:
                num_of_org += 1
                org_first.add(first_words[i])
                org_second.add(second_words[i])
                non_explained.remove(i)
                b = False
                break
        if b:
            break

    first_not_exp = set()
    second_not_exp = set()

    for i in non_explained:
        if first_words[i] not in org_first:
            first_not_exp.add(first_words[i])
        elif second_words[i] not in org_second:
            second_not_exp.add(second_words[i])

    num_of_org += len(first_not_exp)
    num_of_org += len(second_not_exp)

    return n - num_of_org

input_file = open(sys.argv[1], "r")
output_file = open(sys.argv[2], "w")

results = []

T = int(input_file.readline().strip())
for i in xrange(T):
    n = int(input_file.readline().strip())
    first_words = []
    second_words = []
    for j in xrange(n):
        l = input_file.readline().strip().split(' ')
        first_words.append(l[0])
        second_words.append(l[1] + 'aaaaaa')
    results.append(solve(n,first_words,second_words))

for i in xrange(T):
    output_file.write("Case #{0}: {1}\n".format(i+1, results[i]))

input_file.close()
output_file.close()