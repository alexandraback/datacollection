inf = open('input.txt', 'r')
ouf = open('output.txt', 'w')

t = int(inf.readline())
c = 0
for i in range(t):
	d = int(inf.readline())
	mine = {}
	mike = set()
	l = list(map(int, inf.readline().split()))
	for j in range(len(l)):
		if l[j] in mike:
			mine[l[j]] += 1
		else:
			mine[l[j]] = 1
			mike.add(l[j])
	ans = 0
	cnt = 0
	k = 0
	flag = False
	for cnt in range(1, 1001):
		for j in range(1001, 0, -1):
			if j in mike and flag == False:
				if cnt > 1:
					ans += k
					if ans + j < min1:
						min1 = ans + j
				if ((j + 1)//2) in mike:
					mine[(j + 1)//2] += mine[j]
				else:
					mine[(j + 1)//2] = mine[j]
					mike.add((j + 1)//2)
				if j//2 in mike:
					mine[j//2] += mine[j]
				else:
					mine[j//2] = mine[j]
					mike.add(j//2)
				k = mine[j]
				mike.remove(j)
				if cnt == 1:
					min1 = j
				if j == 1:
					flag = True
				break









	print('Case #', end = '', file = ouf)
	print(i + 1, end = '', file = ouf)
	print(':', end = ' ', file = ouf)
	print(min1, file = ouf)

inf.close()
ouf.close()


