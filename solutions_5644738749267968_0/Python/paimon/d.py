def strategy1(l1, l2):
	res = 0
	j, m = 0, len(l2)
	for i in range(len(l1)):
		if j < m:
			if l1[i] > l2[j]:
				res += 1
				j += 1
			else:
				m -= 1
		else:
			break
	return res

def strategy2(l1, l2):
	j = 0
	for i in range(len(l1)):
		while j < len(l2) and l2[j] < l1[i]:
			j += 1
		if j == len(l2):
			return len(l1) - i
		else:
			j += 1
	else:
		return 0
	
answer = 'Case #{0}: {1} {2}'
fin, fout = open('d.in'), open('d.out', 'w')
t = int(fin.readline())
for i in range(t):
	n = int(fin.readline())
	l1 = [float(w) for w in fin.readline().split()]
	l2 = [float(w) for w in fin.readline().split()]
	l1.sort()
	l2.sort()
	r1 = strategy1(l1, l2)
	r2 = strategy2(l1, l2) 
	print(answer.format(i + 1, r1, r2), file=fout)
fin.close()
fout.close()
