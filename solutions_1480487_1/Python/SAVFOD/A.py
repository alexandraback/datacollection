f = open('A.in', "r")
res = open('A.txt', "w")
T = int(f.readline())
for line in xrange(0,T):
	s = f.readline()
	s_numbers = s.split()
	N = int(s_numbers[0])
	numbers=[]
	for cur in xrange(0, N):
		numbers.append(int(s_numbers[cur + 1]))
	X = sum(numbers)
	
	middle = min(numbers)
	for cur in xrange(0, N):
		copy = map(lambda x: max(numbers[cur], x), numbers)
		s = sum(copy)
		if s <= 2 * X:
			middle = max(middle, numbers[cur])
		
		
	
	small_numbers = []
	for cur in xrange(0, N):
		if numbers[cur] <= middle :
			small_numbers.append(numbers[cur])
	
	answer = ""
	
	
	for cur in xrange(0, N):
		new_value = (sum(small_numbers) + sum(numbers))/float(len(small_numbers))
		answer = answer + " " + str(max(100 * (new_value - numbers[cur])/float(sum(numbers)) ,0))

	res.write('Case #' + str(line + 1) + ':' + str(answer) + '\n')

