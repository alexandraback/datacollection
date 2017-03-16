import pygraph
from pygraph.classes.digraph import digraph
#from pygraph.classes.graph import graph
from pygraph.algorithms import cycles, traversal

number_of_cases = int(raw_input())
for case_number in xrange(1, number_of_cases+1):
    number_of_classes = int(raw_input())

    g = digraph()
    g.add_nodes(range(1, number_of_classes+1))
    for i in xrange(1, number_of_classes+1):
        line_as_ints = map(int, raw_input().split())
        for edge_dest in line_as_ints[1:]:
            #print "Add", i, edge_dest
            g.add_edge((i, edge_dest))


    result = ''
    for node in g.nodes():
        if result != '':
            break
        #print node
        l = []
        for neighbor in g.neighbors(node):
            l.append( set (list(traversal.traversal(g, neighbor, 'pre')) ) )

        r = set([])
        for s in l:
#            print '-------'
#            print "r=", r
#            print "s=", s
            if r.intersection(s):
                result = 'Yes'
                break
            else:
                r = r.union(s)

    else:
        result = 'No'

    print "Case #%d: %s" % (case_number, result)
    case_number += 1