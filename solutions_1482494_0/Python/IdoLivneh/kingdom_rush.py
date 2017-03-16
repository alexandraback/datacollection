import sys

def main(filepath):
	with file('kingdom_output.txt', 'wb') as f_out:
		with file(filepath, 'rb') as f_in:
			for line_index, line in enumerate(f_in):
				if line_index == 0: #T
					new_case = True
					case_counter = 1
					continue
				if new_case:
					input_list = line.strip().split(' ')
					number_of_levels = int(input_list[0])
					new_case = False
					level_index = 0
					levels = []
					stars = 0
					round_counter = 0
					invalid = False
					continue
				
				if not invalid:
					input_list = line.strip().split(' ')
					print "level_index: %d, input: %s " % (level_index, input_list)
					one_star = int(input_list[0])
					two_star = int(input_list[1])
				
				
				
					if two_star > 2 * number_of_levels:
						f_out.write("Case #%d: Too Bad\n" % case_counter)
						invalid = True
						
					levels.append([one_star, two_star, 0])
				
				level_index += 1
				
				if level_index == number_of_levels:
					if not invalid:
						print "N=%d, levels: %s" % (number_of_levels, levels)
						
						
						while True:
							print "\tlevels: %s\n\tstars: %d, counter:%d\n" % (levels, stars, round_counter)
							restart = False
							for level in levels:
								if level[1] <= stars:
									round_counter += 1
									stars += 2 - level[2]
									levels.remove(level)
									restart = True
									break
							if restart:
								continue
							for level in levels:
								if level[0] <= stars and not level[2]:
									round_counter += 1
									stars += 1
									level[2] = 1
									restart = True
									break
							if restart:
								continue
							if len(levels):
								output = "Too Bad"
							else:
								output = str(round_counter)
							break
								
									
						
						
						
						
						f_out.write("Case #%d: %s\n" % (case_counter, output))
					
					new_case = True
					case_counter += 1
				
				
					
					
					
					
				
				
if __name__ == '__main__':
	main(sys.argv[1])