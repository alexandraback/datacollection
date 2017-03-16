import sys

def energyGain(e, E, R, V):
	#print e, E, R, V
	startingE = e
	if len(V) == 0:
		#print "GAIN 0"
		return 0
	i = 0
	gain = 0
	while i <= e:
		e = e - i
		#print "GAIN : " + str((e)*V[0]) + " SPEND : " + str(e)
		gain = max(gain, (e)*V[0] + energyGain(min(E, i + R), E, R, V[1:]))
		#print gain
		i += 1
		e = startingE
	return gain

T = int(sys.stdin.readline())
i = 0
while(i < T):
	line = sys.stdin.readline().split()
	E = int(line[0])
	R = int(line[1])
	V = []
	for num in sys.stdin.readline().split():
		V.append(int(num))
	print "Case #" + str(i+1) + ": " + str(energyGain(E, E, R, V))
	i += 1