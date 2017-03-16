#Shrey Gupta
#Problem B

from random import randint

f1 = open('problemB.in', 'r')
f2 = open('problemB.out', 'w')

n = int(f1.readline().strip("\n"))

for x in range(n):
	data = f1.readline().strip("\n").split(" ")
	k = int(data[0]); l = int(data[1]); s = int(data[2])
	keyboard = f1.readline().strip("\n")
	target = f1.readline().strip("\n")

	targetM = ""
	for i in range(0, s):
		targetM += target[i%l]

	startB = 0
	for i in range(0, s-l+1):
		if targetM[i:i+l] == target:
			startB += 1

	'''
	giveB = 1
	for i in range(0, l):
		giveB *= keyboard.count(target[i])/k

	#print(giveB)

	leftB = startB - giveB*(s-l+1)

	for c in target:
		if c not in keyboard:
			leftB = 0.0

	if giveB == 1: leftB = 0.0

	'''
	giveB = 0
	for i in range(100000):
		temp = ""
		for j in range(0, s):
			temp += keyboard[randint(0, k-1)]
		for i in range(0, s-l+1):
			if temp[i:i+l] == target:
				giveB += 1

	leftB = startB - giveB/100000

	out = "Case #" + str(x+1) + ": " + str(leftB) + "\n"
	f2.write(out)