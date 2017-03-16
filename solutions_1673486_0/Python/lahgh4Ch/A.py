def backspace(A, B, p, x):
	correct = 1.0
	for i in range(A - x):
		correct = correct * p[i]
	exc = correct * (B - A + 1 + 2 * x)
	rest = (1 - correct) * (B - A + 1 + B + 1 + 2 * x)
	return exc + rest

def rightAway(A, B, p):
	return B + 2

T = int(raw_input())
for t in range(T):
	line = raw_input()
	A, B = line.split()
	A = int(A)
	B = int(B)
	line = raw_input()
	p = []
	for p_i in line.split():
		p.append(float(p_i))
	expected = []
	for x in range(A + 1):
		expected.append(backspace(A, B, p, x))
	expected.append(rightAway(A, B, p))
	print 'Case #' + str(t + 1) + ':', min(expected)
