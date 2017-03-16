import sys

input_list = []
output_list = []

def get_y(r, t):
	r = long(r)
	t = int(t)
#	print r, t, (-2*r+1+((4*(r**2)-4*r+1+8*t)**0.5))*0.25, (-2*r+1+((4*(r**2)-4*r+1+8*t)**0.5)) 
	return long((-2*r+1+((4*(r**2)-4*r+1+8*t)**0.5))*0.25)

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
	
	result = get_y(input_line[0], input_line[1])
	output_list.append([result])

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
