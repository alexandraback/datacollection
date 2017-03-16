#!/usr/bin/python
import math
def get(k, c):
	ret = list()
	itr = 0
	while itr < k:
		t = 0
		deb = ""
		for i in range(c):
			if itr >= k:
				n = k - 1
			else:
				n = itr
			t = t*k + n
			deb += str(n)
			itr +=1

		ret.append(t+1)
		#print "A", deb, t
	return ret


T = int(raw_input())
for i in range(T):
	line = raw_input()
	k, c, s = line.split()
	k, c, s = int(k), int(c), int(s)

	req = math.ceil(float(k) / c)
	#print "Q",k, c, s
	if req > s:
		print "Case #%d: IMPOSSIBLE" % (i+1)
	else:
		ans = get(k, c)	
		print "Case #%d:" % (i+1), 
		for j in ans:
			print j,
		print
