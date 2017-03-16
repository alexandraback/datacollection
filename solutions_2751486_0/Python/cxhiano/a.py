fin = open('a.in', 'r')
fout = open('a.out', 'w')

T = eval(fin.readline())

def read():
	return fin.readline().split(' ')

def nread():
	return map(eval, read())


for t in range(T):
	ans = 0
	data = read()
	word = data[0]
	n = eval(data[1])
	j = cnt = 0
	try:
		for i in range(len(word)):
			while cnt < n:
				if j == len(word):
					raise Exception
				if word[j] in ['a', 'e', 'i', 'o', 'u']:
					cnt = 0
				else:
					cnt += 1
				j += 1
			ans += len(word) - j + 1
			if j - i <= n:
				cnt -= 1
	except:
		pass
	finally:
		fout.write('Case #%d: %d\n' % (t + 1, ans))
