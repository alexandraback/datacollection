from sys import stdin

def doAct(maxE, R, N, E, val, act):
	if act == N-1:
		return val[act] * E
	maxGain = 0
	for i in range(E+1):
		maxGain = max(maxGain, val[act]*i+ doAct(maxE, R, N, min(maxE, R+E-i), val, act+1))
	return maxGain

input = stdin.readlines()

for i in range(1, 1+int(input[0])):
	line = input[2*i-1].split()
	E, R, N = int(line[0]), int(line[1]), int(line[2])
	line = input[2*i].split()
	val = {}
	for j in range(N):
		val[j] = int(line[j])

	print "Case #{0}: {1}".format(i, doAct(E, R, N, E, val, 0))