import copy

def read_pairs(f, N, vector):
	s_numbers = f.readline()
	s_numbers = s_numbers.split()
	if not 2*N == len(s_numbers):
		raise Exception("DEBUG exception1")
	
	for i in xrange(0, N):
		a = long(s_numbers[2*i    ])
		b = long(s_numbers[2*i + 1])
		vector.append([a,b])
	
def optimize(pair_vector):
	smth_changed = True
	while smth_changed:
		smth_changed = False
		for i in xrange(0, len(pair_vector) - 1):
			if (pair_vector[i])[1] == (pair_vector[i+1])[1]:
				a,b = pair_vector.pop(i+1)
				(pair_vector[i])[0] = (pair_vector[i])[0] + a
				smth_changed = True
				break

	
def add_to_three(pair_vector):
	while (len(pair_vector) < 3):
		pair_vector.append([0,-1])	
	
	
f = open('B.in', "r")
res = open('B.txt', "w")
T = int(f.readline())
for line in xrange(0,T):
	s = f.readline()
	s = s.split()
	N, M = int(s[0]), int(s[1])
	
	boxes_numbers=[]
	read_pairs(f, N, boxes_numbers)
	
	toys_numbers = []
	read_pairs(f, M, toys_numbers)
	
	optimize(boxes_numbers)
	add_to_three(boxes_numbers)
	optimize(toys_numbers)
	
	N = len(boxes_numbers)
	M = len(toys_numbers)
	
	answer = long(0)
	
	#print boxes_numbers
	#print toys_numbers
	
	for sep1 in xrange(0, M):
		for sep2 in xrange(sep1, M):
	#		print sep1, sep2
			new_answer = long(0)
			
			box_copy = copy.deepcopy(boxes_numbers)
			toy_copy = copy.deepcopy(toys_numbers)
						
			for i1 in xrange(0, sep1 + 1):
				if (box_copy[0])[1] == (toy_copy[i1])[1]:
					success = min((box_copy[0])[0], (toy_copy[i1])[0])
					new_answer = new_answer + success
					(box_copy[0])[0] = (box_copy[0])[0] - success
					(toy_copy[i1])[0] = (toy_copy[i1])[0] - success
	#				print i1, success, "i1"
				
			for i2 in xrange(sep1, sep2 + 1):
				if (box_copy[1])[1] == (toy_copy[i2])[1]:
					success = min((box_copy[1])[0], (toy_copy[i2])[0])
					new_answer = new_answer + success
					(box_copy[1])[0] = (box_copy[1])[0] - success
					(toy_copy[i2])[0] = (toy_copy[i2])[0] - success
	#				print i2, success, "i2"
			
			for i3 in xrange(sep2, M):
				if (box_copy[2])[1] == (toy_copy[i3])[1]:
					success = min((box_copy[2])[0], (toy_copy[i3])[0])
					new_answer = new_answer + success
					(box_copy[2])[0] = (box_copy[2])[0] - success
					(toy_copy[i3])[0] = (toy_copy[i3])[0] - success
	#				print i3, success, "i3"
			
	#		print new_answer
			
			answer = max(answer, new_answer)
	
	
	res.write('Case #' + str(line + 1) + ': ' + str(answer) + '\n')

