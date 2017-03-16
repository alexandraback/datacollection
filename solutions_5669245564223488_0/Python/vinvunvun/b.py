from collections import *
from math import *
inFile = open("input.txt", "r")

outFile = open("out.txt", "w")

T = int(inFile.readline())

for t in xrange(T):
	outFile.write("Case #" + str(t+1) + ": ")
	k = inFile.readline()
	trains = inFile.readline().rstrip().split(" ")
	is_any_pure = False
	not_pures = []
	count_pure = Counter()
	pure_characters = set()
	for train in trains:
		if len(set(train)) == 1:
			#pure
			count_pure[train[0]] += 1
			is_any_pure = True
			pure_characters.add(train[0])
		else:
			not_pures.append(train)

	visited = [False]*len(not_pures)
	is_possible = True
	not_pures_characters = set()
	addition_k = 0
	if len(not_pures) != 0:
		left = not_pures[0][0]
		right = not_pures[0][-1]
		visited[0] = True
		total = not_pures[0]
		total_1 = ""
		while not all(visited):
			is_try = False
			for i, train in enumerate(not_pures):
				if not visited[i]:
					if train[0] == right:
						is_try = True
						visited[i] = True
						total += train
						right = train[-1]
					elif train[-1] == left:
						is_try = True
						visited[i] = True
						left = train[0]
						total = train + total
			if is_try is False:
				addition_k += 1
				total_1 += total
				for i in xrange(len(visited)):
					if not visited[i]:
						total = not_pures[i]
						left = not_pures[i][0]
						right = not_pures[i][-1]
						visited[i] = True

		total_1 += total
		total = total_1
		print(is_possible)
		if is_possible:
			visited_c = defaultdict(bool)
			for i in xrange(len(total)):
				if i > 0 and total[i] == total[i-1]:
					continue
				if not visited_c[total[i]]:
					visited_c[total[i]] = True
					not_pures_characters.add(total[i])
				else:
					is_possible = False
					break

					
	if not is_possible:
		outFile.write("0")
	else:
		result = 1
		for c in count_pure:
			result = result*factorial(count_pure[c])
			result %= 1000000007

		inter = pure_characters - not_pures_characters
		k = len(inter)
		if len(not_pures) > 0:
			k += addition_k + 1
		result = result*factorial(k)
		result %= 1000000007 
		outFile.write(str(result))
	outFile.write("\n")



