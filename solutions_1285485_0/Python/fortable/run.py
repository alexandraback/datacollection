#!/usr/bin/python
import sys
dist = lambda x1, x2, y1, y2: ((x2-x1) ** 2. + (y1 - y2) ** 2.) ** 0.5

def inline(p1, p2):
		if dist(p1[0], 0, p1[1], 0) < dist(p2[0], 0, p2[1], 0):
				return False
		if p1[0] == 0.0:
				if p2[0] == 0.0: return p1[1] * p2[1] > 0
				else: return False
		if p2[0] == 0: return False
		return (p1[1] - 0) / (p1[0] - 0) == (p2[1] - 0) / (p2[0] - 0) and \
						p1[0] * p2[0] > 0

def simple_solve(up, down, left, right, D):
 		w_loop = int (D / (2*left + 2 * right) + 1)
		h_loop = int (D / (2*up + 2 * down) + 1)
	#	res = []
	#	for i in range(-w_loop , w_loop + 1):
	#			for j in range(-h_loop, h_loop + 1):	
	#					res.append(( 2 * (left + right) * i,
	#							     2 * (up   + down ) * j))

	#					res.append((-2 * left + 2 * (left + right) * i,
	#							    -2 * down + 2 * (up   + down ) * j))
	#					res.append(( 2 *right + 2 * (left + right) * i,
	#							    -2 * down + 2 * (up   + down ) * j))
	#					res.append((-2 * left + 2 * (left + right) * i,
	#							     2 * up+    2 * (up   + down ) * j))
	#					res.append(( 2 * right +2 * (left + right) * i,
	#							     2 * up    +2 * (up   + down ) * j))

	#					res.append((-2 * left + 2 * (left + right) * i,
	#							     			2 * (up   + down ) * j))
	#					res.append(( 2 *right + 2 * (left + right) * i,
	#							     			2 * (up   + down ) * j))
	#					res.append(( 			2 * (left + right) * i,
	#							     2 * up+    2 * (up   + down ) * j))
	#					res.append((  			2 * (left + right) * i,
	#							     2 * up    +2 * (up   + down ) * j))
	#	res = list(set(res))
		res = set([])
		for i in range(-w_loop , w_loop + 1):
				for j in range(-h_loop, h_loop + 1):	
						res.add(( 2 * (left + right) * i,
								     2 * (up   + down ) * j))

						res.add((-2 * left + 2 * (left + right) * i,
								    -2 * down + 2 * (up   + down ) * j))
						res.add(( 2 *right + 2 * (left + right) * i,
								    -2 * down + 2 * (up   + down ) * j))
						res.add((-2 * left + 2 * (left + right) * i,
								     2 * up+    2 * (up   + down ) * j))
						res.add(( 2 * right +2 * (left + right) * i,
								     2 * up    +2 * (up   + down ) * j))

						res.add((-2 * left + 2 * (left + right) * i,
								     			2 * (up   + down ) * j))
						res.add(( 2 *right + 2 * (left + right) * i,
								     			2 * (up   + down ) * j))
						res.add(( 			2 * (left + right) * i,
								     2 * up+    2 * (up   + down ) * j))
						res.add((  			2 * (left + right) * i,
								     2 * up    +2 * (up   + down ) * j))
		res = list(res)
		res = filter(lambda p: dist(p[0],0,p[1],0) <= D, res)
		
		return res

def solve(up, down, left, right, d):
		res = simple_solve(up, down, left, right, d)
		res = sorted(res, key = lambda x: dist(x[0],0,x[1],0))
		res = filter(lambda i: len(filter(lambda j: inline(i,j), res))<=1, res)
		return len(res) -1

if __name__ == "__main__":
		n = int(sys.stdin.readline())
		c = 1
		while n > 0:
				d = sys.stdin.readline().split(" ")
				H, W, D = map(lambda x: int(x), d)
				for y in range(1, H+1):
						data = sys.stdin.readline()
						for x in range(1, W+1):
								if data[x-1] == 'X':
										print "Case #"+str(c)+": "+str(solve( 	y - 1.5, 
														-y + H - 0.5,
														x - 1.5,
														-x + W - 0.5,
														D))
				n -= 1
				c += 1

