from collections import deque

def fake(firstWords, secondWords):
	firstWordList = []
	secondWordList = []

	fake = 0

	for i in range(0, len(firstWords)):
		if(firstWords[i] in firstWordList):
			if(secondWords[i] in secondWordList):
				fake += 1
			else:
				secondWordList.append(secondWords[i])
		else:
			firstWordList.append(firstWords[i])
			if(secondWords[i] not in secondWordList):
				secondWordList.append(secondWords[i])
	return fake

def fakeMax(firstWords, secondWords):

	d1 = deque(firstWords)
	d2 = deque(secondWords)

	maxNum = fake(list(d1), list(d2))
	for i in range(0, len(list(d1))):
		d1.rotate(1)
		d2.rotate(1)
		if(maxNum < fake(list(d1), list(d2))):
			maxNum = fake(list(d1), list(d2))
	return maxNum

f = open('C-small-attempt1.in-2.txt', 'r')
f2 = open('outputSmall.txt', 'w')
final = ''

for i in range(1, int(f.readline().strip())+1):
	firstWords = []
	secondWords = []
	s = f.readline().strip()
	for j in range(0, int(s)):
		l = f.readline().strip()
		l = l.split()
		firstWords.append(l[0])
		secondWords.append(l[1])
	final += 'Case #{}: {}\n'.format(i, fakeMax(firstWords, secondWords))

f2.write(final)
