# [7, 8, 10, 10, 9, 2, 9, 6, 3, 3]

def findRing(sList): # [2 2 3 0]
	leftIndex = findLeftIndex(sList) # 0
	
	ans = [sList[leftIndex]] # [2]
	left = leftIndex # 0
	right = leftIndex # 0

	sList[leftIndex] = None #[None, 3,4,1]

	while 1:
		if sList[ans[-1]] != None:
			right = ans[-1] # 3
			ans.append(sList[ans[-1]]) # [2,3,0]
			sList[ans[-2]] = None # [None, 2, None, None]
		else:
			break

	flag = True
	
	while flag:
		flag = False

		index = 0

		while index < len(sList):
			if sList[index] == left:
				ans.insert(0, sList[index])
				left = sList[index]
				sList[index] = None
				flag = True
			if sList[index] == right:
				ans.append(sList[index])
				right = sList[index]
				sList[index] = None
				flag = True
			index += 1

	return ans


def findLeftIndex(sList):
	index = 0
	while index < len(sList):
		if sList[index] != None:
			return index
		index += 1

	return None

def stest(sList):
	index = 0
	while index < len(sList):
		if sList[index] != None:
			return True
		index += 1

	return False


t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
	n= int(raw_input().split(" ")[0])  # read a list of integers, 2 in this case
	students = [int(s) for s in raw_input().split(" ")]  # read a list of integers, 2 in this case
	
	index = 0
	while index < len(students):
		students[index] = students[index] - 1
		index += 1

	ringList = []

	while stest(students):
		ringList.append(findRing(students))

	ii = 0
	maxLen = 0
	maxii = 0

	# print ringList
	
	while ii < len(ringList):
		if len(ringList[ii]) > maxLen:
			maxLen = len(ringList[ii])
			maxii = ii
		ii += 1

	print "Case #{}: {}".format(i, len(ringList[maxii]))
