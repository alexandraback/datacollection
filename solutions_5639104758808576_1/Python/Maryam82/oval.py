def main():
	file_name = 'A-large.in'
	f = open(file_name , 'r')
	lines = f.read().splitlines()
	numC = int(lines[0])
	result = ''
	for i in xrange(1, numC + 1):
		line = lines[i]
		sp = line.split()
		shyness = sp[1]
		al_st = 0
		friends_needed = 0
		for j in xrange(len(shyness)):
			s = int(shyness[j])
			if j <= al_st:
				al_st += s
			else:
				diff = j - al_st
				friends_needed += diff
				al_st += (diff + s)
		r = "Case #" + str(i) + ": " + str(friends_needed) + '\n'
		result += r
	print result
	f = open('maryamOval.out', 'w')
	f.write(result)
	f.close()
if __name__ == '__main__':
	main()
