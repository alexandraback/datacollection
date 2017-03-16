import re

def Ryan(n, stars):
	times = 0
	star = 0
	while len(stars) > 0:
		keys = stars.keys()
		onestar = 0
		find = 0
		for i in range(len(keys)):
			level = stars[keys[i]]
			#we can't do a 2-star, try to remember possible 1-star
			if level[1] > star:
				if star >= level[0] and level[2] == 0:
					if onestar == 0 or level[1] > stars[onestar][1]: 
						onestar = keys[i]

			else: #do 2-star
				times = times + 1
				if level[2] == 0:
					#print str(star) + "+ 2 @" + str(keys[i]) + "[2star]"
					star = star + 2
				else:
					#print str(star) + "+ 1 @" + str(keys[i]) + "[1star]"
					star = star + 1
				del stars[keys[i]]
				find = 1
		#try 1-star
		if find == 0:
			if (onestar == 0):
				return 0
			level = stars[onestar]
			#print str(star) + "+ 1 @" + str(onestar) + "[1star]"
			star = star + 1
			level[2] = 1
			times = times + 1

	return times

def round1a1(filepath):
	f = open(filepath, 'r+')
	infile = re.split('in', filepath)
	outfile = infile[0] + "out"
	print outfile
	o = open(outfile, "w+")
	#number of test cases
	t = int(f.readline())

	for i in range(t):
		n = int(f.readline())
		stars = {}
		for j in range(n):
			line = f.readline()
			sl = re.split(" ", line)
			stars[j + 1] = [int(sl[0]), int(sl[1]), 0]
		print str(n) + str(stars)
		result = Ryan(n, stars)
		res = ""
		if result == 0:
			res = "Too Bad"
		else:
			res = str(result)
		#result = recycledNumbers(sl[0], sl[1], len(sl[0]))
		buf = "Case #" + str(i + 1) + ": " + res
		i = i + 1
		print buf
		o.write(buf + '\n')
	f.close()
	o.close()

round1a1("./B-small-attempt1.in")
#round1a1("./B-test.in")