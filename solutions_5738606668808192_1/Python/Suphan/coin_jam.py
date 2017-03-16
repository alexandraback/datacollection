def rwh_primes(n):
    sieve = [True] * n
    for i in xrange(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)/(2*i)+1)
    return [2] + [i for i in xrange(3,n,2) if sieve[i]]




f = open('C-large.in')
fw = open('C-large.out', 'w')

cases = int(f.readline())
for case in range(cases):
	N, J = map(int, f.readline().split())
	A = '1' + ('0' * (N - 2)) + '1'
	
	primes = rwh_primes(1000000)

	fw.write('Case #' + str(case + 1) + ':\n')

	found = 0
	while True:
		ok_for_all_base = True
		solution = []
		for base in range(2, 11):
			num = int(A, base)
			ok_for_this_base = False
			for p in primes:
				if p >= num:
					break
				if num % p == 0:
					ok_for_this_base = True
					solution.append(p)
					break
			if not ok_for_this_base:
				ok_for_all_base = False
				break

		if ok_for_all_base:
			fw.write(A)
			for d in solution:
				fw.write(' ' + str(d))
			fw.write('\n')
			
			found += 1
			if found == J:
				break
		A = "{0:b}".format(int(A, 2) + 2)

fw.close()
f.close()
