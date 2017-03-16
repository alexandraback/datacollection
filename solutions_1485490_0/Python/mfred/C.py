input = open('small.in', 'r').read()
# input="""4
# 3 3
# 10 1 20 2 25 3
# 10 2 30 3 20 1
# 3 5
# 10 1 6 2 10 1
# 5 1 3 2 10 1 3 2 5 1
# 3 5
# 10 1 6 2 10 1
# 5 1 6 2 10 1 6 2 5 1
# 1 1
# 5000000 10
# 5000000 100"""


lines = input.split("\n")

cur_line = 1
i=1

def best_prod(cA,cB):
	
	if len(cB) == 0 or len(cA) == 0:
		return 0
	
	if len(cA) == 1 and len(cB) == 1:
		if cA[0][1] == cB[0][1]:
			return min(cA[0][0],cB[0][0])
		else:
			return 0
	
	if cA[0][1] == cB[0][1]:
		if cA[0][0]<cB[0][0]:
			ncA = cA[1:]
			ncB = [(cB[0][0]-cA[0][0],cB[0][1])]+cB[1:]
			best_prod_next = best_prod(ncA,ncB)
			return cA[0][0]+best_prod_next
		elif cA[0][0] > cB[0][0]:
			ncB = cB[1:]
			ncA = [(cA[0][0]-cB[0][0],cA[0][1])]+cA[1:]
			best_prod_next = best_prod(ncA,ncB)
			return cB[0][0]+best_prod_next
		else:
			ncA = cA[1:]
			ncB = cB[1:]
			return cB[0][0]+best_prod(ncA,ncB)
	else:
		# soit on jette les premiers de la chaine A
		ncA1 = cA[1:]
		ncB1 = cB
		r1 = best_prod(ncA1,ncB1)
		#soit on jette les premiers de la chaine B
		ncA2 = cA
		ncB2 = cB[1:]
		r2 = best_prod(ncA2,ncB2)
		return max(r1,r2)

while cur_line<len(lines)-1:
	line = lines[cur_line].split(" ")
	N = int(line[0])
	M = int(line[1])
	cur_line += 1
	
	line = lines[cur_line].split(" ")
	cA = []
	for j in range(0,len(line)/2):
		cA += [(int(line[2*j]), int(line[2*j+1]))]
	cur_line +=1
	line = lines[cur_line].split(" ")
	cB = []
	for j in range(0,len(line)/2):
		cB += [(int(line[2*j]), int(line[2*j+1]))]
	cur_line +=1
	# print N,M,cA,cB
	
	print "Case #"+str(i)+": "+str(best_prod(cA,cB))
	i += 1



def stringArrayToVector(arr):
	res = []
	for s in arr:
		res += [int(s)]
	return res