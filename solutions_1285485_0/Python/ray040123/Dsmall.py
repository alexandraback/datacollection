import math
from pprint import pprint
from vec2d import Vec2d

def read():
	global i0, j0, n, m, d, mp
	n, m, d = map(int, raw_input().split())
	mp = {}
	for i in xrange(n):
		s = raw_input()
		for j in xrange(m):
			mp[i, j] = s[j]
			if s[j] == 'X':
				i0 = i
				j0 = j

class Set:
	def __init__(self):
		self.a = []

	def add(self, item):
		for i in self.a:
			if i == item:
				return
		self.a.append(item)

	def __len__(self):
		return len(self.a)

def pmp(self):
	for i in xrange(n):
		print ''.join(mp[i, j] for j in xrange(m))

def solve():
	x0 = j0 - 0.5
	y0 = i0 - 0.5
	w, h = m - 2, n - 2
	ps = [(x0, y0), (2*w-x0, y0), (2*w-x0, 2*h-y0), (x0, 2*h-y0)]
	ps = map(Vec2d, ps)
	images = set()
	jcnt = d / (w*2) + 5
	icnt = d / (h*2) + 5
	# print jcnt, icnt
	for j in xrange(-jcnt, jcnt+1):
		for i in xrange(-icnt, icnt+1):
			nps = [p + Vec2d(w*2*j, h*2*i) for p in ps]
			for p in nps:
				dp = p - Vec2d(x0, y0)
				# print dp
				if dp.length() <= d+1e-8:
					images.add(dp.normalized())
	ans = len(images) - 1
	# pprint(images)
	print ans

tot = int(raw_input())
for ti in xrange(tot):
	read()
	# pmp(mp)
	print 'Case #%d:' %(ti+1),
	solve()
