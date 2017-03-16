import sys

input_list = []
output_list = []

# for one case
def get_n(target_x, target_y):
	target_total = abs(target_x)+abs(target_y)
	target_total_odd = target_total %2
	n = 1
	while True:
		if n * (n+1) / 2 >= target_total:
			if ((n * (n+1) / 2) - target_total) %2 == 0:
				return n
			else:
				n += 1
				continue
		else:
			n += 1
			continue

def get_result(target_x, target_y):
	n = get_n(target_x, target_y)
	cur_x = 0
	cur_y = 0
	result = ''
	for x in range(n):
		# x = 0, 1, 2, .., n-1
		# n-x to? EWNS
		if abs(target_x - cur_x) >= abs(target_y - cur_y):
			#x
			if target_x >= cur_x:
				#E n-x
				cur_x += n-x
				result = 'E' + result
			else:
				#W n-x
				cur_x -= n-x
				result = 'W' + result
				#result.insert(0, 'W')
		else:
			#y
			if target_y >= cur_y:
				#N n-x
				cur_y += n-x
				result = 'N' + result
				#result.insert(0, 'N')
			else:
				#S n-x
				cur_y -= n-x
				result = 'S' + result
				#result.insert(0, 'S')
		print result, cur_x, cur_y
	return result

try:
	input_filename = sys.argv[1]
	output_filename = input_filename[:sys.argv[1].find('.')]+'.out'
except:
	print 'input filename as argv'
	exit()

try:
	input_f = open("./"+input_filename)
	input_lines = input_f.readlines()
	input_count = 0
	for input_line in input_lines:
		input_split = input_line.split()
		input_list.append(input_split)
	input_f.close()
except:
	print 'read error'
	exit()

input_list.pop(0)

for input_line in input_list:
	# do some works here
	result = get_result(long(input_line[0]), long(input_line[1]))
	output_list.append([result])
	print

try:
	output_f = open("./"+output_filename, "w")
	output_f.close()
except:
	pass

try:
	output_f = open("./"+output_filename, "a")
	output_str = ''

	for x in range(len(output_list)):
		output_f.write('Case #' + str(x+1)+': '+str(output_list[x][0])+"\n")
		print x
	output_f.close()
except:
	print 'write error'
	exit()
