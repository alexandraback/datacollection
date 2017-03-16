from sys import stdin

def getOpt(size,lst):
	if size == 1:
		return len(lst)
	lst.sort();
	price = [0] * len(lst)
	res = 0
	i = 0
	while i < len(lst):
		n = lst[i]
		while size <= n:
			size = size*2 - 1
			price[i] += 1
		size += n
		i += 1
#	print price
	finalprice = [0] * len(lst)
	finalprice[0] = price[0] + len(lst) - 1
	res = finalprice[0]
	i = 1
	while i < len(lst):
		finalprice[i] = finalprice[i-1] + price[i] - 1
		if finalprice[i] < res:
			res = finalprice[i]
		i+=1
#	print finalprice
	return min(res, len(lst))
	
file = stdin
T = int(file.readline())
for i in range(0,T):
	temp = file.readline().split(" ")
	size = int(temp[0])
	motes = temp[1]
	lst = [int(r) for r in file.readline().split(" ")]
	print 'Case #{0}: {1}'.format(str(i+1),str(getOpt(size,lst)))

