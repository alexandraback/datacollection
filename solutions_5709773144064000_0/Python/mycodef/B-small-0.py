#!/usr/bin/python

f = open("B-small-0.in", "r")
f2 = open("B-small-0.out", "w")

def main2():
	C, F, X = map(float, f.readline().split())

	def cost(n):
		t = 0.0
		cps = 2.0
		for i in xrange(n):
			t += C / cps
			cps += F
		return t + X / cps

	def ternarySearch(n):
		lo, hi = 0, n
		while lo < hi:
			mid = (lo + hi) / 2
			z0 = cost(mid - 1)
			if cost(mid) < cost(mid + 1):
				hi = mid
			else:
				lo = mid + 1
		return lo

	f2.write("%.10f" % (cost(ternarySearch(100001))))


tk = int(f.readline())

for i in xrange(tk):
	f2.write("Case #%d: " % (i + 1))
	main2()
	f2.write('\n')


f.close()
f2.close()