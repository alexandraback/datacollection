f = open('test.txt', 'r')
fout = open("output.txt", "w")
case = 0
even = 0
A = 0
N = 0
for line in f:
	if case == 0:
		case+=1
		continue
	if even == 0:
		line = line.split()
		A = int(line[0])
		N = int(line[1])
		even = 1
	else:
		n =sorted([int(x) for x in line.split()] )
		norig = n
		even = 0
		count = 0
		posscount = 100000
		while(N > 0):
			if len(n) == 0:
				break
			if A > n[0]:
				A += n[0]
				n = n[1:]
			else:
				if A + A - 1 <= n[0]:
					if(posscount == 100000):
						posscount = count + len(n)
						print posscount
				if(count > posscount):
					break
				A += A - 1
				count += 1
		count = min(posscount, count)
		fout.write("Case #" + str(case) + ": " + str(count) + "\n")
		case += 1
