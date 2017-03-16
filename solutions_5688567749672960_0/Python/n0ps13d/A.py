fin = open('A-small-attempt0.in', 'r')
fout = open('A.out', 'w')

cases = int(fin.readline().rstrip('\n'))

def rev(number):
	string = str(number)
	l = list(string)
	l.reverse()
	return int("".join(l))

# print rev(1300)

for case in xrange(1, cases+1):
	# print case
	answer = 'Case #' + str(case) + ': '
	N = int(fin.readline().rstrip('\n'))
	a = [float('inf')]*(N+1)
	a[1] = 1
	for n in xrange(2, N+1):
		if rev(n) < N and n % 10 != 0:
			a[n] = 1 + min(a[n-1], a[rev(n)])
		else:
			a[n] = 1 + a[n-1]
		# print n, n-1, rev(n)

	answer += str(a[N])
	print answer



fin.close()
fout.close()