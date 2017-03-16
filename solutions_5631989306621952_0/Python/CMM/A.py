def solve(s):
	z = s[0]
	for c in s[1:]:
		if (c+z) < (z+c):
			z = z + c
		else:
			z = c + z
	return z
			

N = int(raw_input())

case = 1
for i in range(N):
	print ("Case #%d:" % case), solve(raw_input())
	case += 1
