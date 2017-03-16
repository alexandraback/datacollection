#!/usr/bin/python

f = open("D-small-0.in", "r")
f2 = open("D-small-0.out", "w")

def main2():
	N = int(f.readline())
	naomi = map(float, f.readline().split())
	ken = map(float, f.readline().split())
	naomi.sort()
	ken.sort()
	fair, unfair = 0, 0
	for x in ken:
		if (x > naomi[fair]) and (fair < N): fair += 1
	for x in naomi:
		if (x > ken[unfair]) and (unfair < N): unfair += 1

	f2.write("%d %d" % (unfair, N - fair))

tk = int(f.readline())

for i in xrange(tk):
	f2.write("Case #%d: " % (i + 1))
	main2()
	f2.write('\n')

f.close()
f2.close()