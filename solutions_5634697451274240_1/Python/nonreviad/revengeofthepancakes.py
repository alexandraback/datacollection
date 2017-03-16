def readInt(file):
	line = f.readline()
	return int(line)
if __name__ == "__main__":
	with open('pancakes.in') as f:
		n = readInt(f)
		for i in range(1, n + 1):
			stack = f.readline()
			stack = stack[:-1] + "+"
			hadHappy = False
			hadSad = False
			res = 0
			for character in list(stack):
				if character == '+':
					if hadSad:
						res = res + 1
						if hadHappy:
							res = res + 1
					hadSad = False
					hadHappy = True
				else:
					hadSad = True
			print ("Case #"+ str(i) + ": " + str(res))