lines = [line.strip() for line in open('in')]
n = lines[0]

cache = dict()
cache['1'] = 1
def answer(i):
	i.lstrip('0')
	if i in cache:
		return cache[i]
	if int(i) == 1:
		return 1
	else:
		num = int(i[::-1])
		if num >= int(i) or int(i) %10 == 0:
			cache[i] = answer(str(int(i)-1)) +1
			return cache[i]
		else:
			cache[i] = min(1+answer(str(int(i)-1)), 1+answer(i[::-1]))
			return cache[i]

for i in range(1,1000000):
	answer(str(i))


for x in range(int(n)):
	g = lines[x+1]
	ans = answer(g)
	print('Case #' + str(x+1) + ': ' + str(ans))
