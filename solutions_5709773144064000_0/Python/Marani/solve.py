import time

file_in = file('test.in', 'r')
file_out = file('test.out', 'w')

def main():
	n_case = int(file_in.readline())
	for case in range(1, n_case + 1):
		solveCase(case)

def solveCase(case_number):
	#in
	c, f, x = map(float, file_in.readline().split())

	#main
	factory_count = 0
	while  c / (2 + factory_count * f) + x / (2 + (factory_count + 1) * f) < x / (2 + factory_count * f):
		factory_count += 1

	factory_time = 0
	for i in range(factory_count):
		factory_time += c / (2 + i * f)

	result = factory_time + x / (2 + factory_count * f)

	#out
	file_out.write("Case #" + repr(case_number) + ": " + ("%.7f" % result) + "\n")


if __name__ == '__main__':
	startTime = time.clock()
	main()
	print (time.clock() - startTime)