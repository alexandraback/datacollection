import sys

def main(input_file):
	number_of_cases = int(input_file.readline().strip("\n"))
	for case_number in xrange(1, number_of_cases + 1):
		print "Case #%d: %s" % (case_number, case(input_file, case_number))

muls = {('1', '1') : '1', ('1', 'i') : 'i',	('1', 'j') : 'j', ('1', 'k') : 'k', ('1', '-1') : '-1', ('1', '-i') : '-i',	('1', '-j') : '-j', ('1', '-k') : '-k',
		('i', '1') : 'i', ('i', 'i') : '-1', ('i', 'j') : 'k', ('i', 'k') : '-j', ('i', '-1') : '-i', ('i', '-i') : '1', ('i', '-j') : '-k', ('i', '-k') : 'j',
		('j', '1') : 'j', ('j', 'i') : '-k', ('j', 'j') : '-1', ('j', 'k') : 'i', ('j', '-1') : '-j', ('j', '-i') : 'k', ('j', '-j') : '1', ('j', '-k') : '-i',
		('k', '1') : 'k', ('k', 'i') : 'j', ('k', 'j') : '-i', ('k', 'k') : '-1', ('k', '-1') : '-k', ('k', '-i') : '-j', ('k', '-j') : 'i', ('k', '-k') : '1',
		('-1', '1') : '-1', ('-1', 'i') : '-i',	('-1', 'j') : '-j', ('-1', 'k') : '-k', ('-1', '-1') : '1', ('-1', '-i') :'i',	('-1', '-j') : 'j', ('-1', '-k') : 'k',
		('-i', '1') : '-i', ('-i', 'i') : '1', ('-i', 'j') : '-k', ('-i', 'k') : 'j', ('-i', '-1') : 'i', ('-i', '-i') : '-1', ('-i', '-j') : 'k', ('-i', '-k') : '-j',
		('-j', '1') : '-j', ('-j', 'i') : 'k', ('-j', 'j') : '1', ('-j', 'k') : '-i', ('-j', '-1') : 'j', ('-j', '-i') : '-k', ('-j', '-j') : '-1', ('-j', '-k') : 'i',
		('-k', '1') : '-k', ('-k', 'i') : '-j', ('-k', 'j') : 'i', ('-k', 'k') : '1', ('-k', '-1') : 'k', ('-k', '-i') : 'j', ('-k', '-j') : '-i', ('-k', '-k') : '-1'}
		
def case(input_file, case_number):
	l, x = map(int, input_file.readline().strip("\n").split())
#	x = x % (l * 12)
	input = input_file.readline().strip("\n") * x
	
	length = l * x
	possible_i, possible_j = -1, -1
	value = '1'
	for i, next_value in enumerate(input):
		value = muls[(value, next_value)]
		if value == 'i':
			possible_i = i
			break
	if possible_i == -1:
		return "NO"
	possible_i += 1
	
	value = '1'
	for j, next_value in enumerate(input[possible_i:]):
		value = muls[(value, next_value)]
		if value == 'j':
			possible_j = j
			break
	if possible_j == -1:
		return "NO"
	possible_j += possible_i + 1
	
	value = '1'
	for k, next_value in enumerate(input[possible_j:]):
		value = muls[(value, next_value)]
	if value != 'k':
		return "NO"
	
	return "YES"
	
if __name__ == '__main__':
	main(open(sys.argv[1]))


