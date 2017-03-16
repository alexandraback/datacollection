vowels = ['a', 'e', 'i', 'o', 'u']

def nValue(string, n):
	val = 0
	for i in range(len(string)):
		for j in range(i, len(string)):
			subString = string[i:j+1]
			count = 0
			for k in subString:
				if k in vowels: count = 0
				else: count += 1
				if count >= n:
					val += 1
					break
	return val


T = int(raw_input())
for t in range(T):
	line = raw_input()
	string, n = line.split(' ')
	n = int(n)
	print 'Case #' + str(t + 1) + ':', nValue(string, n)
