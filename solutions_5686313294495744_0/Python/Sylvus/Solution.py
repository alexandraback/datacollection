# Language       : Python 3
# Compiled Using : py_compile
# Version        : Python 3.4.3

import networkx as nx
from networkx.algorithms.bipartite.matching import hopcroft_karp_matching
from networkx.algorithms.bipartite.matching import eppstein_matching
from functools import partial
from itertools import chain
from nose.tools import assert_equal, assert_true, assert_false


def arbitrary_element(iterable):
    return next(iter(iterable))


def min_edge_cover_sub(G, matching_algorithm=None):
    """Returns a set of edges which constitutes
    the minimum edge cover of the graph.
    A smallest edge cover can be found in polynomial time by finding
    a maximum matching and extending it greedily so that all nodes
    are covered.
    Parameters
    ----------
    G : NetworkX graph
        An undirected bipartite graph.
    matching_algorithm : function
        A function that returns a maximum cardinality matching in a
        given bipartite graph. The function must take one input, the
        graph ``G``, and return a dictionary mapping each node to its
        mate. If not specified,
        :func:`~networkx.algorithms.bipartite.matching.hopcroft_karp_matching`
        will be used. Other possibilities include
        :func:`~networkx.algorithms.bipartite.matching.eppstein_matching`,
        or matching algorithms in the
        :mod:`networkx.algorithms.matching` module.
    Returns
    -------
    min_cover : set
        It contains all the edges of minimum edge cover
        in form of tuples.
    Notes
    -----
    An edge cover of a graph is a set of edges such that every node of
    the graph is incident to at least one edge of the set.
    The minimum edge cover is an edge covering of smallest cardinality.
    Due to its implementation, the worst-case running time of this algorithm
    is bounded by the worst-case running time of the function
    ``matching_algorithm``.
    Minimum edge cover for bipartite graph can also be found using the
    function present in :mod:`networkx.algorithms.bipartite.covering`
    """
    if matching_algorithm is None:
        matching_algorithm = partial(nx.max_weight_matching,
                                     maxcardinality=True)
    maximum_matching = matching_algorithm(G)
    # ``min_cover`` is superset of ``maximum_matching``
    min_cover = set(maximum_matching.items())
    # iterate for uncovered nodes
    uncovered_nodes = set(G) - {v for u, v in min_cover}
    for v in uncovered_nodes:
        # Since `v` is uncovered, each edge incident to `v` will join it
        # with a covered node (otherwise, if there were an edge joining
        # uncovered nodes `u` and `v`, the maximum matching algorithm
        # would have found it), so we can choose an arbitrary edge
        # incident to `v`. (This applies only in a simple graph, not a
        # multigraph.)
        #
        # Since the graph is guaranteed to be undirected, we need only
        # add a single orientation of the edge.
        u = arbitrary_element(G[v])
        min_cover.add((u, v))
        min_cover.add((v, u))
    return min_cover

def is_edge_cover(G, cover):
    """Decides whether a set of edges is a valid edge cover of the graph.
    Given a set of edges, whether it is an edge covering can
    be decided if we just check whether all nodes of the graph
    has an edge from the set, incident on it.
    Parameters
    ----------
    G : NetworkX graph
        An undirected bipartite graph.
    cover : set
        Set of edges to be checked.
    Returns
    -------
    bool
        Whether the set of edges is a valid edge cover of the graph.
    Notes
    -----
    An edge cover of a graph is a set of edges such that every node of
    the graph is incident to at least one edge of the set.
    """
    return set(G) <= set(chain.from_iterable(cover))


def min_edge_cover(G, matching_algorithm=None):
    """Returns a set of edges which constitutes
    the minimum edge cover of the graph.
    The smallest edge cover can be found in polynomial time by finding
    a maximum matching and extending it greedily so that all nodes
    are covered.
    Parameters
    ----------
    G : NetworkX graph
        An undirected bipartite graph.
    matching_algorithm : function
        A function that returns a maximum cardinality matching in a
        given bipartite graph. The function must take one input, the
        graph ``G``, and return a dictionary mapping each node to its
        mate. If not specified,
        :func:`~networkx.algorithms.bipartite.matching.hopcroft_karp_matching`
        will be used. Other possibilities include
        :func:`~networkx.algorithms.bipartite.matching.eppstein_matching`,
    Returns
    -------
    set
        A set of the edges in a minimum edge cover of the graph, given as
        pairs of nodes.
    Notes
    -----
    An edge cover of a graph is a set of edges such that every node of
    the graph is incident to at least one edge of the set.
    A minimum edge cover is an edge covering of smallest cardinality.
    Due to its implementation, the worst-case running time of this algorithm
    is bounded by the worst-case running time of the function
    ``matching_algorithm``.
    """
    if matching_algorithm is None:
        matching_algorithm = hopcroft_karp_matching
    return min_edge_cover_sub(G, matching_algorithm=matching_algorithm)



with open("C-small-attempt0.in") as f:
    data = f.readlines()


counter_line = 0
number_of_test_cases = int(data[counter_line][:-1])
counter_line += 1

for test_case_counter in range(number_of_test_cases):
    number_of_topics = int(data[counter_line][:-1])
    counter_line += 1
    word_to_index1 = {}
    word_to_index2 = {}
    word_to_index_counter = 0
    G = nx.Graph()
    for i in range(number_of_topics):
        line = data[counter_line][:-1].split(" ")
        counter_line += 1

        if line[0] not in word_to_index1:
            word_to_index1[line[0]] = word_to_index_counter
            G.add_node(word_to_index_counter)
            word_to_index_counter += 1

        if line[1] not in word_to_index2:
            word_to_index2[line[1]] = word_to_index_counter
            G.add_node(word_to_index_counter)
            word_to_index_counter += 1

        G.add_edge(word_to_index1[line[0]], word_to_index2[line[1]])
    min_cover = min_edge_cover(G)
    print("Case #" + str(test_case_counter+1) + ": " + str(int(number_of_topics - len(min_cover) / 2)))

#G = nx.complete_graph(10)
#print(G)
#min_cover = min_edge_cover(G)
#assert_true(is_edge_cover(G, min_cover))
#assert_equal(len(min_cover), 10)
#print(len(min_cover))


