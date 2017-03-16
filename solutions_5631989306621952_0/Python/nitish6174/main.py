from math import *

t = int(input())

for itr in range(0,t):
	s = list(input())
	t = []
	t.append(s[0])
	for i in range(1,len(s)):
		c = s[i]
		if c>=t[0]:
			t = [c]+t
		else:
			t.append(c)
	print("Case #"+str(itr+1)+": "+''.join(t))
