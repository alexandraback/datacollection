import sys

def guess(N, M, K, products):
	m = M
	cards = []
	i = 0
	while len(cards) < 3 and i < K:
		while m > 1 and products[i] != 1 and len(cards) < N:
			#print products[i], m
			if products[i]%m == 0:
				cards.append(str(m))
				products[i] /= m
				m += 1
			m -= 1
		i += 1
		m = M
	#print len(cards)
	while len(cards) < N:
		cards.append(str(2))
	return "".join(cards)

T = int(sys.stdin.readline())
i = 0
while(i < T):
	line = sys.stdin.readline().split()
	R = int(line[0])
	N = int(line[1])
	M = int(line[2])
	K = int(line[3])
	print "Case #" + str(i+1) + ": "
	j = 0
	while j < R:
		products = []
		for num in sys.stdin.readline().split():
			products.append(int(num))
		products.sort()
		products.reverse()
		print guess(N, M, K, products)
		j += 1
	i += 1