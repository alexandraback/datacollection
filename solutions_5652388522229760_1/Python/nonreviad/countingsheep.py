def readInt(file):
	line = f.readline()
	return int(line)
def markFound(found, number):
	if number == 0:
		found[0] = True;
		return found
	while number > 0:
		found[number % 10] = True
		number = number / 10
	return found
def hasAllTrue(l):
	for i in l:
		if i == False:
			return False
	return True
if __name__ == "__main__":
	with open('countingsheep.in') as f:
		n = readInt(f)
		for i in range(1, n + 1):
			x = readInt(f)
			if x == 0:
				print ("Case #" + str(i) + ": INSOMNIA")
			else:
				found = [False, False, False, False, False, False, False, False, False, False]
				num = x
				while True:
					found = markFound(found, num)
					if hasAllTrue(found):
						break
					num = num + x
				print ("Case #" + str(i) + ": " + str(num))