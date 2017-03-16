def main():
	file_name = 'A-large.in'
	f = open(file_name , 'r')
	lines = f.read().splitlines()
	test_cases = int(lines[0])
	result = ''
	for i in xrange(1, test_cases + 1):
		line = lines[i]
		sp = line.split()
		shyness = sp[1]
		stoods = 0
		friends_needed = 0
		for j in xrange(len(shyness)):
			s = int(shyness[j])
			if j <= stoods:
				stoods += s
			else:
				diff = j - stoods
				friends_needed += diff
				stoods += (diff + s)
		r = "Case #" + str(i) + ": " + str(friends_needed) + '\n'
		result += r
	print result
	f = open('q1.out', 'w')
	f.write(result)
	f.close()
if __name__ == '__main__':
	main()
