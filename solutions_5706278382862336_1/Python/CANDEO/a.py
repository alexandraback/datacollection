def gcd(a, b):
    while b:
        a, b = b, a%b
    return a
	
import sys

input_list = []
output_list = []

def get_result(P, Q):
	P_long = long(P) 
	Q_long = long(Q)
	GCD = gcd(P_long, Q_long)
	P_fr = P_long/GCD
	Q_fr = Q_long/GCD
	if len(bin(Q_fr).split('1')) > 2:
		return 'impossible'
	return str(len(bin(Q_fr))-len(bin(P_fr)))

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
		input_split = input_line.split('/')
		input_list.append(input_split)
	input_f.close()
except:
	print 'read error'
	exit()

input_list.pop(0)

for input_line in input_list:
	# do some works here
#	print input_list
	result = get_result(input_line[0], input_line[1])
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
