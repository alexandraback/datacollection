import math

q_file_name = "B-small-attempt1.in"
out_file_name = "out_" + q_file_name

out_file = file(out_file_name, "w")

q_file = file(q_file_name)

cases = int(q_file.readline())


def legal(arr):
	str = ''.join(arr)
	lst = []
	current = None
	for c in str:
		if (c in lst and current != c):
			return False
		current = c
		lst.append(c)
	return True

def rebuild(param):
	newstr = param[0]
	for c in param:
		if (newstr[-1] != c):
			newstr += c
	return newstr



for i in xrange(cases):
	
	carts_num = int(q_file.readline())
	carts = q_file.readline().replace("\n", "").split(" ")
	for c in range(len(carts)):
		carts[c] = rebuild(carts[c])

	if (i % 10 == 0):
		print i
	ways = []
	if (carts_num > 0):
		ways = [[]]

		for j in range(carts_num):
			new_ways = []
			for way in ways:
				for k in range(len(way) + 1):
					temp = way[:]	
					temp.insert(k, carts[j])
					#print temp
					if legal(temp):
						new_ways.append(temp)
			ways = new_ways
			#print len(ways)
	out_file.write("Case #" + str(i+1) + ": " + str(len(ways) % 1000000007) + "\n")






