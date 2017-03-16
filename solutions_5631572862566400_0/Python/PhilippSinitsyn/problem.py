import sys
import os
import math
import networkx as nx

# in = sys.stdin
fin = open('C-small-attempt0.in')
# fout = sys.stdout
fout = open('out_1', 'w')


def solve(friends):
	fr = dict(friends)
	g = nx.DiGraph()

	for f in friends:
		if(fr[f[1]] == f[0]):
			for q in friends:
				if f != q:
					g.add_edge(f, q) 
		g.add_edge(f, (f[1], fr[f[1]]))

	return max([len(x) for x in nx.simple_cycles(g)])


if __name__ == '__main__':
    count = int(fin.readline())

    for i in range(count):
    	count = int(fin.readline().strip())
    	friends = list(enumerate(map(int, fin.readline().strip().split()), 1))
        fout.write('Case #%s: %s\n' % (i + 1, solve(friends)))


