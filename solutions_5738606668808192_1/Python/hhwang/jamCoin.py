

def make_1_position(n,k):
	""" make a list of binary strings of length n with k 1s """
	if k == 0:
		result = ''
		for i in xrange(n):
			result += '0'
		return [result]
	elif n == k:
		result = ''
		for i in xrange(n):
			result += '1'
		return [result]
	else:
		result = []
		for string in make_1_position(n-1,k-1):
			result.append('1'+string)
		for string in make_1_position(n-1,k):
			result.append('0'+string)
		return result


T = int(raw_input())

for i in xrange(1,T+1):
	# make expression divisible by x+1 when N is even
	N, J = [int(value) for value in raw_input().split(' ')] 
	print "Case #{}:".format(i)

	for num_1 in xrange(0, N/2-1):
		odd_position = make_1_position(N/2-1, num_1)
		even_position = make_1_position(N/2-1, num_1)
		for odd_pos in odd_position:
			for even_pos in even_position:
				number = '1'
				for i in xrange(N/2-1):
					number += even_pos[i] + odd_pos[i]
				number = number + '1'
				print number + " 3 4 5 6 7 8 9 10 11"
				J-= 1
				if J==0:
					break
			if J==0:
				break
		if J==0:
			break