#!/usr/bin/pypy

import sys

def solve(N, S, p, t):
		#print N, S, p, t
		q1 = len(filter(lambda x: x==0, t))
		if q1 != 0:
				if p == 0: 
						return len(t)
				else:
						t = filter(lambda x: x!= 0, t)
		mod1 = len(filter(lambda x: x % 3 == 1 and int(x / 3) >= p-1, t))
		
		mod0 = len(filter(lambda x: x % 3 == 0 and int(x / 3) >= p - 1, t)) 
		mod2 = len(filter(lambda x: x % 3 == 2 and int(x / 3) >= p - 2, t))
		mod0s =len(filter(lambda x: x % 3 == 0 and int(x / 3) >= p, t))
		mod2s =len(filter(lambda x: x % 3 == 2 and int(x / 3) >= p-1, t))
		#print mod1, mod0, mod2
		mod1 += mod0s + mod2s
		mod0 -= mod0s
		mod2 -= mod2s
		#print mod1, mod0, mod2
		#print "--------------"
		res = mod1 + min(S, mod0 + mod2)
		return res

if __name__ == "__main__":
		sys.stdin.readline()
		data = sys.stdin.readlines()
		c = 1
		for i in data:
				t = map(lambda x: int(x), i.split(' '))
				N, S, p = t[0], t[1], t[2]
				t = t[3:]
				print "Case #"+str(c)+": "+str(solve(N, S, p, t))
				c += 1
