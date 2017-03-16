from math import sqrt, floor, ceil

count = 0
dp = [0]

for i in range(1,10**7+1):
	if str(i)==str(i)[::-1]:
		if str(i**2)==str(i**2)[::-1]:
			count += 1
	dp.append(count)

f = open("C-small-attempt0.in", "r")
g = open("answer.txt", "w")

N = int(f.readline().split()[0])
for i in range(N):
	x,y = map(int, f.readline().split())
	g.write("Case #{}: {}\n".format(i+1, dp[int(floor(sqrt(y)))]-dp[int(ceil(sqrt(x)))-1]))
f.close()
g.close()
