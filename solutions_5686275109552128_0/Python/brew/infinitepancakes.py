import math

def solve(pancakes):
	time = 0
	possibletimes = [max(pancakes)]
	while(True):
		frequency = [0 for x in range(9)]
		for x in pancakes:
			frequency[x-1] += 1
		bottleneck = max(pancakes)
		
		if(bottleneck == 1):
			possibletimes.append(time+1)
			break

		# Construct the possibility of splitting up the max in newdiners.

		newdiners = [y for y in pancakes if y < bottleneck]
		people = frequency[bottleneck-1]
		newdiners.extend([int(math.ceil(float(bottleneck)/2))] * people)
		newdiners.extend([int(math.floor(float(bottleneck)/2))] * people)

		# Add the cost of entertaining this possibility to time. 
		
		time += people

		# If we stopped sharing at this point, the cost would have been... 

		possibletimes.append(time + max(newdiners))
		pancakes = newdiners
		

	return min(possibletimes)

def solve_bruteforce(pancakes):
	originalsetting = [x for x in pancakes]
	worstcasetime = max(pancakes)
	answer = worstcasetime
	# guessedtime is a guess of the number of special minutes
	for guessedtime in range(worstcasetime):
		for specialminutes in range(guessedtime):
			bottleneck = max(pancakes)
			pancakes.remove(max(pancakes))
			newpancakes = [x for x in pancakes]
			newpancakes.extend([int(math.ceil(float(bottleneck)/2)),int(math.floor(float(bottleneck)/2))])
			pancakes = newpancakes
		answer = min(answer,guessedtime+max(pancakes))
		pancakes = [x for x in originalsetting]
	return answer

def solveDP(pancakes):

	#Fail!

	SDopt = [[0, 0], [0, 1], [0, 2], [0, 3], [1, 2], [1, 3], [1, 3], [2, 3], [2, 3], [2, 3]]
	pancakes.sort()
	solution = [[0,0] for x in pancakes]

	for i in range(len(pancakes)):
		if i == 0:
			solution[0] = SDopt[pancakes[0]]
		elif sum(solution[i-1]) >= pancakes[i]:
			solution[i] = solution[i-1]
		else:
			bottleneck = pancakes[i]
			
			#NEVER MIND!!!

			w1 = SDopt[bottleneck][0]
			s1 = SDopt[bottleneck][1]

			w2 = solution[i-1][0]
			s2 = solution[i-1][1]

			if(w1+w2 + max(s1,s2) < bottleneck):
				solution[i] = [w1+w2,max(s1,s2)] 
			else:
				solution[i] = [0,bottleneck]

	return solution

def singlediner(p):
	if p == 1:
		return [0,1]
	if p == 2:
		return [0,2]
	answer = [0,p]
	for z in range(1,p):
		w1 = singlediner(z)[0]
		w2 = singlediner(p-z)[0]
		s1 = singlediner(z)[1]
		s2 = singlediner(p-z)[1]
		if (1+w1+w2+max(s1,s2)) < sum(answer):
			answer = [1+w1+w2,max(s1,s2)]
		if 1+w1+w2+max(s1,s2) == sum(answer) and 1+w1+w2 < answer[0]:
			answer = [1+w1+w2,max(s1,s2)]
	return answer


def solveDPreloaded(pancakes):

	frequency = [0 for x in range(9)]
	for x in pancakes:
		frequency[x-1] += 1


	bottleneck = max(pancakes)
	answer = bottleneck
	if bottleneck == 1:
		return 1
	if bottleneck == 2:
		return 2
	if frequency[bottleneck-1] >= bottleneck:
		return bottleneck
	
	people = frequency[bottleneck-1]

	g = open("understand.txt","a")

	for z in range(1,bottleneck):
		newdiners = [y for y in pancakes if y < bottleneck]
		newdiners.extend([z] * people)
		newdiners.extend([bottleneck-z] * people)
		subanswer =  solveDPreloaded(newdiners)

		answer = min(answer, people + subanswer)


	if bottleneck == 9:
		print answer
		
	return answer


	
g = open("B-small-5-out.txt","w")

f = open("B-small-attempt5.in","r")
d = f.read().split("\n")
n = int(d[0])

j = 1
for i in range(1,2*n+1,2):
	pc = [int(x) for x in d[i+1].split(" ")]
	g.write ("Case #" + str((i+1)/2) + ": " + str(solveDPreloaded(pc)) + "\n")

# SDopt = []
# for i in range(10):
# 	SDopt.append(singlediner(i))
# print SDopt


print solveDPreloaded([9,6])
print "\n\n\n"