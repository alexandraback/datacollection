def nextPancake(pancake):
	if pancake == '+':
		return 1
	else:
		return 0

f = open('large2.in')
T = int(f.readline().strip())



i = 0
for k in range(T):
	i+=1
	totalFlips = 1
	pancakes = f.readline().strip()
	nowPancake = nextPancake(pancakes[0])
	for j in range(len(pancakes) - 1):
		onePancake = nextPancake(pancakes[j+1])
		if (onePancake != nowPancake):
			nowPancake = onePancake
			totalFlips+=1
	if (nowPancake == 1):
		totalFlips-=1
	print "Case #%d: %d" %(i, totalFlips)