def main():
	#read file
	f_name = 'A-large.in.txt'
	f = open(f_name , 'r')
	lines_file = f.read().splitlines()
	# read test cases
	test_cases = int(lines_file[0])
	result = ''
	#here it is

	for i in xrange(1, test_cases + 1):
		line = lines_file[i]
		sp = line.split()
		f_shy = sp[1]
		stoods = 0
		friends_needed = 0
		for j in xrange(len(f_shy)):
			s = int(f_shy[j])
			if j <= stoods:
				stoods += s
			else:
				diff = j - stoods
				friends_needed += diff
				stoods += (diff + s)
		res = "Case #" + str(i) + ": " + str(friends_needed) + '\n'
		result += res
	print result
	f = open('saber_ovation.out', 'w')
	f.write(result)
	f.close()
if __name__ == '__main__':
	main()
