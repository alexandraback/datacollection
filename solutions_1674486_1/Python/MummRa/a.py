
import sys, string, math, bisect
from itertools import permutations
rl = lambda: sys.stdin.readline().strip()

for cs in xrange(1,int(rl())+1):
	n=int(rl())
	parents=[-1]*n
	for i in xrange(n):
		ll=[int(z)-1 for z in rl().split()[1:]]
		parents[i]=ll
	#print parents
	
	anc=[-1]*n
	#print anc

	ans=False
	for nodeouter in xrange(n):
		for node in xrange(n):
			#print 'NODE:',node, anc
			all_parents_not_known_yet=False
			knownps=set(parents[node])
			if len(parents[node])==0:
				anc[node]=set()
			else:
				for parentnode in parents[node]:
			#		print 'node, parentnode, ancs',node,parentnode,anc[parentnode]
					if anc[parentnode]==-1:
						all_parents_not_known_yet=True
						break
					#all parents of nodeinner are known!
					newps=anc[parentnode]
					if len(knownps.intersection(newps))!=0:
						ans=True
						break
					else:
						knownps.update(newps)
				if ans==True:
					break
				if all_parents_not_known_yet:
					continue
				anc[node]=knownps
		if ans==True:
			break
	print "Case #{0}: {1}".format(cs, "Yes" if ans else "No")
	
	