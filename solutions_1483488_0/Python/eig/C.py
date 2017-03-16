def main(A,B):
	N = 10 ** (len(str(A))-1)
	count = 0

	for n in xrange(A,B+1):
		numbers = {}
		numbers[n]=True

		m = n/10 + (n%10)*N

		while m not in numbers:
			if m <= B and m>n:
				numbers[m]=True
				count+=1
			m = m/10 + (m%10)*N
	return count



if __name__ == '__main__':
	import sys
	T = int(sys.stdin.readline())
	for i in xrange(T):
		[A,B] = map(int, sys.stdin.readline().split(' '))
		res = main(A,B)
		print "Case #%d: %d" % (i + 1,res)
