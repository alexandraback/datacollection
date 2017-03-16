MAXN = 1000000
B = 13

inf = open("a.in", 'r')
outf = open("a.out", 'w')

def count_all():
	produced_numbers = {}

	for i in xrange(1, B):
		produced_numbers[i] = i
	for i in xrange(B, MAXN + 1):
		produced_numbers[i] = -1
	cur_numbers = [B - 1]
	while (cur_numbers):
		next_numbers = []
		for x in cur_numbers:
			if (x + 1 <= MAXN) and (produced_numbers[x + 1] == -1):
				produced_numbers[x + 1] = produced_numbers[x] + 1
				next_numbers.append(x + 1)
			tmp = (str(x))[::-1]
			tmp = int(tmp)
			if (tmp <= MAXN) and (produced_numbers[tmp] == -1):
				produced_numbers[tmp] = produced_numbers[x] + 1
				next_numbers.append(tmp)
		print next_numbers
		cur_numbers = next_numbers
	return produced_numbers

ca = count_all()

t = int(inf.readline())

for k in xrange(0, t):
	n = int(inf.readline())		
	outf.write("Case #" + str(k + 1) + ": ")	
	outf.write(str(ca[n]) + "\n")
outf.close()
