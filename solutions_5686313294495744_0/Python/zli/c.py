import sys
#http://www.ics.uci.edu/~eppstein/PADS/
#David Eppstein's python library
sys.path.append("pads")

from collections import defaultdict
import BipartiteMatching

for case in range(1, input()+1):
    print "Case #%s:" % (case),
    topics = []
    for topic in range(1, input()+1):
        topics.append(raw_input().split())
    #print topics
    g = defaultdict(list)
    h = defaultdict(list)
    for first, second in topics:
        g["l_%s" % first].append("r_%s" % second)
        h["r_%s" % second].append("l_%s" % first)
    #print g
    matching = BipartiteMatching.matching(g)[0]
    #print matching
    remainder = len(g) + len(h) - 2*len(matching)
    #print len(topics), len(matching), len(g), remainder
    print len(topics) - len(matching) - remainder
