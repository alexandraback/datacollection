import time

file_in = file('test.in', 'r')
file_out = file('test.out', 'w')

def main():
	n_case = int(file_in.readline())
	for case in range(1, n_case + 1):
		solveCase(case)

def solveCase(case_number):
	#in
	n = int(file_in.readline())
	a = map(float, file_in.readline().split())
	b = map(float, file_in.readline().split())

	#main
	c = map(lambda item: ('a', item), a) + map(lambda item: ('b', item), b)
	d = sorted(c, key=(lambda item: item[1]))
	e = map(lambda item: item[0], d)
	print e
	smaller_b = 0
	max_d_war = 0
	max_war = 0
	for item in e:
		if item == 'a':
			if smaller_b > 0:
				max_d_war += 1
				smaller_b -= 1
		else:
			smaller_b += 1

	a = sorted(a)
	b = sorted(b)
	chosen = [False for i in range(n)]
	bottom = 0
	max_war = n
	for i in range(n):
		# search for closest, else choose smallest
		found = False
		k = -1
		for j in reversed(range(n)):
			if (((j > 0) and (b[j] > a[i]) and (b[j - 1] < a[i])) or
				((j == 0) and (b[j] > a[i]))):
				k = j
				break

		if k > -1:
			for j in range(k, n):
				if not chosen[j]:
					chosen[j] = True
					found = True
					max_war -= 1
					break

		if not found:
			for j in range(0, n):
				if not chosen[j]:
					chosen[j] = True
					break



	print max_d_war, max_war

	#out
	file_out.write("Case #" + repr(case_number) + ": " + repr(max_d_war) + " " + repr(max_war) + "\n")


if __name__ == '__main__':
	startTime = time.clock()
	main()
	print (time.clock() - startTime)