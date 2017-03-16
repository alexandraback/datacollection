import fileinput
stdin = fileinput.input()

def solveCase():
	n  = int(stdin.next())
	b_n = sorted(map(float,stdin.next().split()))
	b_k = sorted(map(float,stdin.next().split()))

	s_dwar = 0
	l_k = 0
	for i in xrange(n):
		if b_n[i]>b_k[l_k]:
			l_k += 1
			s_dwar += 1

	s_war = 0
	h_k = n-1
	for i in xrange(n):
		if b_n[n-1-i]<=b_k[h_k]:
			h_k -= 1
		else:
			s_war += 1

	return str(s_dwar)+' '+str(s_war)

for case in xrange(int(stdin.next())):
	print "Case #{0}: {1}".format(case+1,solveCase())
