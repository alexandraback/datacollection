import re

def f(L, n):
	num = 0
	for i in range(len(L)+1):
		for j in range(i+1, len(L)+1):
			#print L[i:j]
			num += 1 if max(map(len, re.split(r'[aeiou]', L[i:j]))) >= n else 0
	return num


T = int(raw_input())

for t in range(T):
	line = raw_input().split()
	L, n = line[0], int(line[1])

	print "Case #{0}: {1}".format(t + 1, f(L, n))