from sys import stdin, stdout
from collections import Counter
t = int(stdin.readline())
for k in range(1, t+1):
	ans = 0
	n = int(stdin.readline())
	inp = []
	for i in range(n):
		inp.append(stdin.readline().strip().split(' '))
	first = Counter([inp[i][0] for i in range(n)])
	second = Counter([inp[i][1] for i in range(n)])
	ans = min(n - len(first), n - len(second))
	stdout.write("Case #"+str(k)+": "+str(ans)+"\n")