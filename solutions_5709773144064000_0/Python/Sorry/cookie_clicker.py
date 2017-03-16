import sys
def main(argv):
	file_name = argv[0]
	f = open(file_name, 'r')
	number_tests = int(f.readline())

	for count in range(number_tests):
		first_line = f.readline()
		first_line = first_line.split()

		first_line = map(float, first_line)

		rate = 2
		cost = first_line[0]
		bonus = first_line[1]
		total = first_line[2]

		#adjustment
		if bonus < 1 and bonus != 0:
			cost /= bonus 
			cost *= total / 100
			bonus = total / 100
			print cost, bonus

		max_so_far = total / rate
		factory_time = 0
		current = max_so_far

		if cost == 0:
			if bonus > 0:
				max_so_far = 0
			elif bonus == 0:
				current += 1
		
		while (max_so_far >= current):
			max_so_far = current
			factory_time += cost / rate
			rate += bonus
			current = factory_time + total / rate

		print "Case #" + str(count+1) + ": %.7f" % max_so_far

if __name__ == "__main__":
   main(sys.argv[1:])
