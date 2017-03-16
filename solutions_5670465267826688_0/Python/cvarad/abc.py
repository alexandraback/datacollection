mult = {('j', '1'): 'j', ('k', 'i'): 'j', ('1', 'j'): 'j', ('1', '1'): '1', ('k', 'j'): '-i', ('1', 'k'): 'k', ('k', 'k'): '-1', ('j', 'i'): '-k', ('k', '1'): 'k', ('i', 'j'): 'k', ('1', 'i'): 'i', ('i', 'k'): '-j', ('j', 'k'): 'i', ('i', 'i'): '-1', ('i', '1'): 'i', ('j', 'j'): '-1'}

def multiply(x, y):
	if x[0] == '-' and y[0] != '-':
		res = mult[x[1], y]
		if res[0] == '-':
			res = res[1]
		else:
			res = '-' + res
		return res

	if x[0] != '-' and y[0] == '-':
		res = mult[x, y[1]]
		if res[0] == '-':
			res = res[1]
		else:
			res = '-' + res
		return res

	if x[0] == '-' and y[0] == '-':
		return mult[x[1], y[1]]

	return mult[x, y]

if __name__ == '__main__':
	t = input()
	for i in range(1, t+1):
		l, x = map(int, raw_input().split())
		s = raw_input()

		if l*x < 3 or len(set(s)) == 1:
			print "Case #" + str(i) + ": NO"
			continue

		s = s*x
		found = 0
		first = '1'
		index = 0

		for a in range(0, len(s)-2):
			first = multiply(first, s[a])
			if first == 'i':
				found = 1
				index = a
				break

		if found == 0:
			print "Case #" + str(i) + ": NO"
			continue

		found = 0
		first = '1'
		for b in range(index+1, len(s)-1):
			first = multiply(first, s[b])
			if first == 'j':
				found = 1
				index = b
				break

		if found == 0:
			print "Case #" + str(i) + ": NO"
			continue

		first = '1'
		for c in range(index+1, len(s)):
			first = multiply(first, s[c])

		if first == 'k':
			print "Case #" + str(i) + ": YES"
		else:
			print "Case #" + str(i) + ": NO"
