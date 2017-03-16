content = open("in.txt", "r").read().split('\n')

def calc(r, n):
	first = 2*r + 1
	last = 2*r + (4*n-3)
	return (first + last) * n / 2

result = ""

for i in range(1, len(content)):
	if len(content[i]) == 0:
		break
	r, t = map(int, content[i].split(' '))

	L, R = 0, 100000000000000000
	while R-L > 1:
		M = (L + R) / 2
		if calc(r, M) <= t:
			L = M
		else:
			R = M
	result += "Case #" + str(i) + ": " + str(L) + "\n"

open("out.txt", "w").write(result)