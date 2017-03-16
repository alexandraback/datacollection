for case in range(1, int(input())+1):
	N = int(input())
	if N == 0:
		result = "INSOMNIA"
	else:
		current = N
		digits = {1,2,3,4,5,6,7,8,9,0}
		while len(digits) > 0:
			analyze = current
			while analyze > 0:
				(analyze, last) = divmod(analyze, 10)
				if (last) in digits:
					digits.remove(last)
			current = current + N 
		result = str(current - N)
	print ("Case #%d: %s" % (case,result))

