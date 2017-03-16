import sys
def main(argv):
	file_name = argv[0]
	f = open(file_name, 'r')
	number_tests = int(f.readline())
	for count in range(number_tests):
		number_pieces = int(f.readline())
		deceit_line1 = f.readline()
		deceit_line2 = f.readline()

		deceit_line1 = deceit_line1.split()
		deceit_line2 = deceit_line2.split()

		deceit_line1 = map(float, deceit_line1)
		deceit_line1.sort()
		deceit_line2 = map(float, deceit_line2)
		deceit_line2.sort()

		war_line1 = list(deceit_line1)
		war_line2 = list(deceit_line2)

		deceit = 0
		war = 0
		war_first_small = True
		deceit_second_small = True
		for piece_count in range(number_pieces):
			full_loop = len(war_line1)
			i = 0
			while (deceit_second_small and deceit_line1[0] < deceit_line2[0] and i < full_loop):
				deceit_line1.append(deceit_line1.pop(0))
				i+=1
			if (not deceit_second_small or deceit_line1[0] < deceit_line2[0]):
				deceit+=1
				deceit_second_small = False

			i = 0
			while (war_first_small and war_line1[0] > war_line2[0] and i < full_loop):
				war_line2.append(war_line2.pop(0))
				i+=1
			if (not war_first_small or war_line1[0] > war_line2[0]):
				war+=1
				war_first_small = False
			deceit_line1 = deceit_line1[1:]
			deceit_line2 = deceit_line2[1:]
			war_line1 = war_line1[1:]
			war_line2 = war_line2[1:]

		print "Case #" + str(count+1) + ": " + str(number_pieces - deceit) + " " + str(war)

if __name__ == "__main__":
   main(sys.argv[1:])
