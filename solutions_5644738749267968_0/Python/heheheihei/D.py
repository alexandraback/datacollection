#! /usr/bin/python

def merge(list0, list1):
	index0 = 0
	index1 = 0
	listRet = []
	length = len(list0)
	while True:
		if list0[index0] < list1[index1]:
			listRet.append(0)
			index0 += 1
		else:
			listRet.append(1)
			index1 += 1
		if index0 == length or index1 == length:
			listRet.extend([1 if index0 == length else 0] * (length * 2 - index0 - index1))
			return listRet

def point(mergeList):
	pointRet = 0
	index = 0
	diff = 0
	while index < len(mergeList):
		if mergeList[index] == 1:
			if diff > 0:
				diff -= 1
				pointRet += 1
		else:
			diff += 1
			
		index += 1
	return pointRet
	
if __name__ == "__main__":
	outputFile = open("D.out", "w") 
	data = [sorted([float(numStr) for numStr in line.split()]) for line in open("D.in", "r")]
	numOfCase = int(data[0][0])
	for caseIndex in range(numOfCase):
		length = int(data[caseIndex * 3 + 1][0])
		list0 = data[caseIndex * 3 + 2]
		list1 = data[caseIndex * 3 + 3]
		mergeList = merge(list0, list1)
		print point([1 - num for num in mergeList]), length - point(mergeList)
		outputContent = 'Case #%d: %d %d\n' % (caseIndex + 1, point([1 - num for num in mergeList]), length - point(mergeList))
		outputFile.write(outputContent)
	outputFile.close()
