import sys
sys.setrecursionlimit(10000)

def f(x):
	#find highest letter
	if len(x) == 0:
		return ''
	highestIndex = 0
	highestLetter = x[0]
	for i,c in enumerate(x):
		if c > highestLetter:
			highestLetter = c
			highestIndex = i

	beginning = f(x[:i])
	middle = []
	end = []
	for c in x[i:]:
		if c == highestLetter:
			middle.append(c)
		else:
			end.append(c)
	return ''.join(middle) + beginning  + ''.join(end)





n = int(input())
for i in range(n):
	x = f(input())
	print("Case #{0}: {1}".format(i+1, x))