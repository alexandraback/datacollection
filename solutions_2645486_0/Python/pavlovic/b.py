import sys

b = int(sys.stdin.readline().strip())

for i in range(b):
	l = sys.stdin.readline().strip().split()
	e = int(l[0])
	r = int(l[1])
	n = int(l[2])

	l = sys.stdin.readline().strip().split()
	act = []
	energy = []

	#minenergy = r
	for j in range(n):
		act.append(int(l[j]))
		energy.append(r)


	maxgain = -1;
	while True:

		#print energy

		gain = 0
		cur_e = e
		valid = True
		for j in range(n):
			gain += energy[j] * act[j]
			cur_e -= energy[j]
			if cur_e < 0:
				valid = False
				energy[j] = e
				break
			cur_e += r
			if (cur_e > e):
				if (cur_e - r > 0):
					valid = False
					break
				cur_e = e

		if (valid and (gain > maxgain)):
			maxgain = gain



		k = 0
		while ((k < n) and (energy[k] == e)):
			energy[k] = r
			k += 1

		if k == n:
			break

		energy[k] += 1


	


	print "Case #" + str(i + 1) + ": " + str(maxgain)

