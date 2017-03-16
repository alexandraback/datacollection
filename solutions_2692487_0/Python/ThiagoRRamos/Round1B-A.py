def do_solve(a,sizes):
	if len(sizes) == 0:
		return 0
	min_value = 1 + do_solve(a,sizes[1:])
	new_value = min_value+1
	if a!=1:
		count = 0
		while a <= sizes[0]:
			count +=1
			a = 2*a-1
		new_value = count+do_solve(a+sizes[0],sizes[1:])
	return min(min_value,new_value)

def solve(a,sizes):
	return do_solve(a,sorted(sizes))

number_of_cases = int(raw_input())
for i in xrange(1,number_of_cases+1):
	a, size_size = [int(x) for x in raw_input().split(" ")]
	size = [int(x) for x in raw_input().split(" ")]
	print "Case #"+str(i)+": "+str(solve(a,size))
