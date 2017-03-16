import collections

input = open('B-small-attempt1.in')
output = open('B-small-attempt1.out', 'w')
num_of_lines = int(input.readline())
num = 0
while num < num_of_lines:
	N = int(input.readline())
	#Ai = []
	#Bi = []
	
	B_hash = collections.defaultdict(list)
	#A_hash = collections.defaultdict(list)
	A_list = []
	used = {}
	finish = {}
	
	for n in xrange(N):
		parts = input.readline().split()
		ai = int(parts[0])
		bi = int(parts[1])
		
		#Ai.append(ai)
		#Bi.append(bi)
		
		B_hash[bi].append(n)
		#A_hash[ai].append((bi, n))
		A_list.append((bi, -ai, n))
	
	#for ai in A_hash:
	#	A_hash[ai].sort()
	A_list.sort()

	last_check = -1
	star = 0
	new_star = 0
	action = 0
	fail = False
	while True:
		for i in range(last_check + 1, star + 1):
			#new_star += len(B_hash[star]) * 2
			for id in B_hash[i]:
				if id in used:
					new_star += 1
					action += 1
				else:
					new_star += 2
					action += 1
				used[id] = 2
				finish[id] = 2
		last_check = star
		
		if new_star > star:
			star = new_star
			if len(finish) == N:
				break
			continue
		
		for j in range(len(A_list)):
			(bi, ai, n) = A_list[len(A_list) - 1 - j]
			if n in used:
				del A_list[len(A_list) - 1 - j]
		
		#while True:	
		#	(bi, ai, n) = A_list[-1]
		#	if n in used:
		#		del A_list[-1]
		#	else:
		#		break
		
		not_fail = False
		for j in range(len(A_list)):
			(bi, ai, n) = A_list[len(A_list) - 1 - j]
			ai *= -1
			if ai <= star:
				star += 1
				new_star += 1
				action += 1
			
				del A_list[len(A_list) - 1 - j]
				used[n] = 1
				not_fail = True
				break
		
		if not not_fail:
			fail = True
			break
	
	if fail:
		output.write('Case #' + str(num + 1) + ': Too Bad\n')
	else:
		output.write('Case #' + str(num + 1) + ': ' + str(action) + '\n')
	num += 1
output.close()
