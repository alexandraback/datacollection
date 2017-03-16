import math

# def maxIndex(pancakeNumbers):
# 	i = len(pancakeNumbers) - 1
# 	while(i >= 0 and pancakeNumbers[i] == 0):
# 		i -= 1
# 	return i

# def minutes(pancakeNumbers):
# 	maxPancakes = maxIndex(pancakeNumbers)
# 	if maxPancakes == -1:
# 		return 0
# 	elif maxPancakes <= 2:
# 		return maxPancakes
# 	else:
# 		numMax = pancakeNumbers[maxPancakes]
# 		newPancakeNumbers = list(pancakeNumbers)
# 		newPancakeNumbers[maxPancakes] = 0
# 		newPancakeNumbers[maxPancakes/2] += numMax
# 		newPancakeNumbers[maxPancakes - maxPancakes/2] += numMax
# 		return min(maxPancakes, numMax + minutes(newPancakeNumbers))

# def minIndex(pancakes):
# 	m = pancakes[0]
# 	j = 0
# 	for i in range(len(pancakes)):
# 		if pancakes[i] < m:
# 			m = pancakes[i]
# 			j = i
# 	return j

def minutes(pancakes):
	maxPancakes = max(pancakes)
	if maxPancakes <= 3:
		return maxPancakes
	else:
		possibleStops = []
		for i in range(2, maxPancakes + 1):
			possibleStops.append(i + stopAt(i, pancakes))
		return min(possibleStops)


def stopAt(m, pancakes):
	sum = 0
	for i in range(len(pancakes)):
		if pancakes[i] > m:
			sum += int(math.ceil(float(pancakes[i])/m)) - 1
	return sum

fin = open("B-small-attempt2.in", 'r')
fout = open("out.txt", 'w')

cases = int(fin.readline())

for case in range(cases):
	diners = int(fin.readline())
	pancakes = map(int, str.split(fin.readline()))
	# pancakeNumbers = [0 for i in range(max(pancakes) + 1)]
	# for i in range(len(pancakes)):
	# 	pancakeNumbers[pancakes[i]] += 1
	fout.write("Case #" + str(case + 1) + ": " + str(minutes(pancakes)) + "\n")

fin.close()
fout.close()