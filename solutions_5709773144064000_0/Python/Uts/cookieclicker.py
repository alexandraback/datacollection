import math

T = int(raw_input())
for t in range(1, T+1):
	params = raw_input().split()
	C = float(params[0])
	F = float(params[1])
	X = float(params[2])
	N = int(max(0, math.ceil((F*X-2*C)/(F*C) - 1)))
	result = 0
	for i in range(0, N):
		result += 1/(2+i*F)
	result = C*result + X/(2+N*F)
	print "Case #%d: %.7f" % (t, result)