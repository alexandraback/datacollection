import math

fi = open("B-large.in")
fo = open("B-large.out", "w")

line = next(fi)
T = int(line)
for t in range(T):
	line = next(fi)
	N = int(line)
	nums = [0 for x in range(2501)]
	for i in range(2*N-1):
		line = next(fi)
		r = line.rstrip().split(' ')
		for rr in r:
			nums[int(rr)] = 1 - nums[int(rr)]

	w = ''
	for n in range(2501):
		if nums[n]:
			w += ' ' + str(n)

	fo.write("Case #" + str(t+1) + ":" + w + "\n")

fi.close()
fo.close()
