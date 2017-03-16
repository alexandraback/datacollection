import itertools
from collections import Counter

t = int(raw_input())
for case in xrange(1,t+1):
	N = int(raw_input())
	lst = [map(int, raw_input().split()) for i in range(1,2*N)]
	lst1 = list(itertools.chain(*lst))
	lst2 = Counter(lst1)
	lst3 = [k for k,v in lst2.iteritems() if v%2!=0]
	lst3 = sorted(lst3)
	lst3 = map(str, lst3)
	#print " ".join(lst3)
	print "Case #%s: %s" % (case, " ".join(lst3))
	
	
		