def r1_a():
	r = open('r1_a.in', 'r')
	w = open('r1_a.out', 'w')
	T = eval(r.readline())
	for c in range(T):
		line = r.readline().split(' ')
		a = eval(line[0])
		b = eval(line[1])
		p = r.readline().split(' ')
		for x in range(a):
			p[x] = eval(p[x])
		val = 1e9*1.0
		# case 1.
		sp = 1.
		for i in range(a):
			sp *= p[i]
		nval = sp*(b-a+1) + (1-sp)*(b-a+1+b+1)
		val = min(val, nval)

		# case 2.
		for k in range(1, a):
			sp = 1.
			for i in range(a-k):
				sp *= p[i]
			nval = sp*(b-a+k+1) + (1-sp)*(b-a+k+1+b+1) + k
			val = min(val, nval)
		nval = a+b+1
		val = min(val, nval)
		
		# case 3.
		nval = 1+b+1
		val = min(val, nval)

		xline = "Case #%d: %f"%(c+1,val)
		print xline
		w.write(xline+'\n')

if __name__ == '__main__':
	r1_a()
