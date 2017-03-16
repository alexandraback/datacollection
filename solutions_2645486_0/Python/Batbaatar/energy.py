def rec(gain, idx, energy, e, R, v):

	if(idx == len(v)):
		return gain

	energy = min(energy + R, e)

	maxv = 0
	maxi = -1
	for i in range(energy + 1):
		temp = rec(gain + v[idx] * i, idx + 1, energy - i, e, R, v)
		if(temp > maxv):
			maxv = temp
			maxi = i

	return maxv

Q = int(input())

for i in range(Q):
	line = raw_input().split(" ")
	E = int(line[0])
	R = int(line[1])
	N = int(line[2])
	
	v = [int(j) for j in raw_input().split(" ")]
	print "Case #" + str(i + 1) + ": " + str(rec(0, 0, E, E, R, v))
