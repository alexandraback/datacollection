#############
# Google Code Jam 2012
# Dancing with the Googlers by Jos Kraaijeveld
# facebook.com/Kaidenceq @JMKraaijeveld
# kaidence.org
#############

import sys


# Open the files and read the arguments
input = open(sys.argv[1])
output = open(sys.argv[2], 'w')
num_cases = int(input.readline())
current = 1

# Loop over the amount of testcases
while current <= num_cases:
	line = input.readline().split(' ')
	num_googlers, surprising, best_result = int(line[0]), int(line[1]), int(line[2])
	
	count = 0
	for dancer in line[3:]:
		dancer = int(dancer)
		# If this dancer has a score equal to three times the result we are looking for minus two,
		# it means this case can be done without having to use up a 'surprising'
		if best_result*3-2 <= dancer:
			count += 1
		# Else, if we still have surprising charges left, and we can use one to make this a
		# valid score, do it. A difference of two (surprising charge) can only occur if best_result
		# is larger than 1.
		elif best_result > 1 and surprising > 0 and best_result*3-4 <= dancer:
			count += 1
			surprising -= 1

	
	output.write("Case #{}: {}\n".format(current, count))
	
	current += 1

input.close()
output.close()
