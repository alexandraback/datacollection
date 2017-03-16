import time

file_in = file('test.inp', 'r')
file_out = file('test.out', 'w')

def main():
	n_case = int(file_in.readline())
	for case in range(1, n_case + 1):
		solveCase(case)

def gcd(a, b):
	if b == 0:
		return a
	else:
		return gcd(b, a % b)


def solveCase(case_number):
	#in
	p, q = map(int, file_in.readline().strip().split('/'))
	print p, q
	#main
	d = gcd(p, q)
	p = p / d
	q = q / d
	t = q
	result = 0
	while t > 1:
		if t % 2 > 0:
			file_out.write("Case #" + repr(case_number) + ": impossible\n")
			return
		t /= 2
	while p < q:
		p *= 2
		result += 1

	print result

	#out
	file_out.write("Case #" + repr(case_number) + ": " + repr(result) + "\n")


if __name__ == '__main__':
	startTime = time.clock()
	main()
	print (time.clock() - startTime)